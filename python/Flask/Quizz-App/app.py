from flask import Flask,render_template,request
from main import firebase
from flask import redirect
app = Flask(__name__)
db=firebase.database()
#Global Varible
global i
i=0
points=0

data=db.child('quizz').child('questions').get()

@app.route('/')
def hello_world():
    try:
        global i
        q=data.val()[i]
        question=q['question']
        option_a=q['answers'][0]
        option_b=q['answers'][1]
        option_c=q['answers'][2]
        option_d=q['answers'][3]
        return render_template('index.html',Question=question,Option_a=option_a,Option_b=option_b,Option_c=option_c,Option_d=option_d)
    except:
        return render_template('scoreboard.html',Points=points)
@app.route('/action-submit',methods=['POST','GET'])
def submit():
    try:
        if request.method=='GET':
            global i
            selectedValue=request.args.get('answer')
            index=data.val()[i]['correctIndex']
            test=data.val()[i]['answers'][index]
            print(test)
            if(selectedValue==data.val()[i]['answers'][index]):
                global points
                points=points+1
            i=i+1
        return hello_world()
    except:
        return Exception





if __name__ == '__main__':
    app.run()
