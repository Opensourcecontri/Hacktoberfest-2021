import sqlite3

connection = sqlite3.connect('animalgram.db')
cursor = connection.cursor()

cursor.execute(
    '''
    CREATE TABLE IF NOT EXISTS user (
        id INTEGER PRIMARY KEY, username TEXT, email TEXT, password TEXT
    );
    '''
)

cursor.execute(
    '''
    CREATE TABLE IF NOT EXISTS post (
        id INTEGER PRIMARY KEY, userid INTEGER, title TEXT, image BLOB,
        FOREIGN KEY (userid) REFERENCES user(id)
    );
    '''
)

cursor.close()
connection.close()
