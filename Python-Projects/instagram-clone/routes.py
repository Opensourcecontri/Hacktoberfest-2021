import os
import sqlite3
from werkzeug.utils import secure_filename
from app import app
from flask import render_template, request, url_for, session, redirect
from helpers import apology, login_required
from werkzeug.security import check_password_hash, generate_password_hash
from base64 import b64encode


@app.route('/')
@login_required
def index():
    posts = []

    connection = sqlite3.connect('animalgram.db')
    cursor = connection.cursor()
    
    temp_posts = cursor.execute('SELECT * FROM post').fetchall()
    for temp_post in temp_posts:
        post = {}
        post['id'] = temp_post[0]
        post['user'] = cursor.execute('SELECT * FROM user WHERE id=?', (temp_post[1],)).fetchone()[1]
        post['title'] = temp_post[2]
        post['image'] = b64encode(temp_post[3]).decode('utf-8')
        posts.append(post)
    
    cursor.close()
    connection.close()

    return render_template('index.html', posts=posts)


@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form.get('name')
        email = request.form.get('email')
        password = request.form.get('password')
        confirm_password = request.form.get('confirm-password')

        if not (username or email or password or confirm_password):
            return apology('Missing information!', 404)
        
        if password != confirm_password:
            return apology("Passwords don't match!")

        connection = sqlite3.connect('animalgram.db')
        cursor = connection.cursor()

        users = cursor.execute('SELECT * FROM user WHERE username=?', (username.strip(),)).fetchall()
        if len(users) != 0:
            return apology('Username is already taken!')
        
        emails = cursor.execute('SELECT * FROM user WHERE email=?', (email.strip(),)).fetchall()
        if len(emails) != 0:
            return apology('Email is already being used!')
        
        cursor.execute(
            'INSERT INTO user (username, email, password) VALUES(?, ?, ?)',
            (username.strip(), email.strip(), generate_password_hash(password))
        )
        connection.commit()
        cursor.close()
        connection.close()
        return redirect(url_for('login'))
    elif request.method == 'GET':
        return render_template('register.html')


@app.route('/login', methods=['GET', 'POST'])
def login():
    session.clear()

    connection = sqlite3.connect('animalgram.db')
    cursor = connection.cursor()

    if request.method == 'POST':
        if not request.form.get('email'):
            return apology('Must provide email', 403)
        elif not request.form.get('password'):
            return apology('Must provide password', 403)
        
        rows = cursor.execute('SELECT * FROM user WHERE email=?', (request.form.get('email').strip(),)).fetchall()
        if len(rows) != 1 or not check_password_hash(rows[0][-1], request.form.get('password')):
            return apology('Invalid email and/or password', 403)
        session['user_id'] = rows[0][0]
        cursor.close()
        connection.close()
        return redirect(url_for('index'))
    elif request.method == 'GET':
        return render_template('login.html')


@app.route('/logout')
@login_required
def logout():
    session.clear()
    return redirect(url_for('index'))


@login_required
@app.route('/create', methods=['GET', 'POST'])
def create_post():
    if request.method == 'POST':
        title = request.form.get('title')
        image = request.form.get('image')

        if not (title or image):
            return apology('Missing information!', 404)

        ALLOWED_EXTENSIONS = ['png', 'jpg', 'jpeg', 'gif']
        file = request.files['image']

        if file and file.filename.split('.')[1] in ALLOWED_EXTENSIONS:
            filename = secure_filename(file.filename)
            file.save(filename)
            
            connection = sqlite3.connect('animalgram.db')
            cursor = connection.cursor()
            
            with open(filename, 'rb') as f:
                image_data = f.read()
            
            os.remove(filename)

            cursor.execute('INSERT INTO post (userid, title, image) VALUES(?, ?, ?)', (session['user_id'], title, image_data))
            connection.commit()

            cursor.close()
            connection.close()

            return redirect(url_for('index'))
        return apology('Not a valid file extension!')
        
    elif request.method == 'GET':
        return render_template('create_post.html')
