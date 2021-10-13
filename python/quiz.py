from random import randint

def ask(q):
  print(q[0])
  for n in range(len(q[1])):
    print(n+1,"-",q[1][n])
  answer = input("Your answer (enter only the digit): ")
  return answer == str(q[2])

question = (("What is the capital of France?",("London","Paris","Rome","Berlin"),2),("This is a question.",("True","False"),1),("Which company produced the first commercially-available computer?",("IBM","ICL","Ferranti","Lyons"),4),("From which material is the moon made?",("Cheese","Apple Pie","Rock"),3),("Which of these isn't one of your favourite things?",("Raindrops on roses","Walnuts","Whiskers on kittens","Bright copper kettles","Warm woollen mittens"),2))
response = (("Well done","Correct","Lucky guess"),("Oops","Sorry","Incorrect"))

print("Welcome to the quiz.  For each question enter a single digit to indicate your choice of answer.\n")
asked = []
score = 0
for n in range(3):
  qu = randint(0,len(question)-1)
  while qu in asked:
    qu = randint(0,len(question)-1)
  asked.append(qu)
  if ask(question[qu]):
    score += 1
    print(response[0][randint(0,2)],"- your score is now",str(score)+".\n")
  else:
    print(response[1][randint(0,2)],"- the answer was",question[qu][1][question[qu][2]-1]+".\n")
print("That was the final question - you scored a total of",str(score)+".")
