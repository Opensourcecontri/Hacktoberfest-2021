import pyrebase
fireconfig={'apiKey': "AIxxxxxxxxxxxxxxxxxxxxxxxWIU",
            'authDomain': "xxxxxxxxx.firebaseapp.com",
            "databaseURL":"https://xxxxxxxxxx-default-rtdb.firebaseio.com/",
            'projectId': "xxxxxxxxxxxxx",
            'storageBucket': "xxxxxxxxxxxxx.appspot.com",
            'messagingSenderId': "xxxxxxxxxx",
            'appId': "x:xxxxxxxxxx:web:xxxxxxxxxxx"
            }

firebase=pyrebase.initialize_app(fireconfig)
auth=firebase.auth()
