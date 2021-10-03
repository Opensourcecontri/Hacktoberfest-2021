# Rock,Paper,Scissors Game
import random

def welcome_msg():
    msg = """
    Welcome to Rock Paper and scissors Game.
    
    Rules:
      1. The game play between computer and one player.
      2. Intially computer choose   and after that it's gives your'e trun.
      3. If you enter any other key except 's', 'r' and 'p' the game will be exit.
      4. If you choose right key then the game will be start.
      5.And lastly it's option to you "Play again or not"
     

    """
    print(msg)
    # Rock
    print("r for")
    print("""
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
""")

# paper
    print("p for")
    print("""
     _______
---'    ____)____
           ______)
          _______)
         _______)
---.__________)
""")

#  scissors
    print("s for")
    print("""
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
""")

def GameWin(comp, you):
        if comp == you:
            return None
        elif comp == 'r':
            if you == 'p':
                return True
            elif you == 's':
                return False
        elif comp == 'p':
            if you == 's':
                return True
            elif you == 'r':
                return False
        elif comp == 's':
            if you == 'r':
                return True
            elif you == 'p':
                return False


welcome_msg()
while True:
    randNO = random.randint(1, 3)
    print("Computer's Turn: Rock(r),Paper(p) and Scissors(s):")
    if randNO == 1:
        comp = "r"
    elif randNO == 2:
        comp = 'p'
    elif randNO == 3:
        comp = 's'
    print("computer Done\n Now it's", end="")
    you = input("Your's Turn: Rock(r),Paper(p) and Scissors(s): ")
    if you != 's' and you != 'r' and you != 'p':
        print("Wrong chose!! PLay carefully.")
        break

    print("computer's chose "+comp)
    print("Your's chose "+you)
    x = GameWin(comp, you)
    if x == None:
        print('''The game is tie!!''')
    elif x:
        print('''YOU WIN''')
    else:
        print('''YOU LOSE!,Try Again ''')
    play_again = input("Play again? (y/n): ")
    if play_again.lower() != "y":
            print("Happy to play with you")
            break
