from flask import Flask
from flask_session import Session
from tempfile import mkdtemp

app = Flask(__name__)

app.config['SESSION_FILE_DIR'] = mkdtemp()
app.config['SESSION_PERMANENT'] = False
app.config['SESSION_TYPE'] = 'filesystem'
Session(app)

from routes import *
if __name__ == '__main__':
    app.run(debug=True)
