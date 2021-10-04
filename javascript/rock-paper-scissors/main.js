var btn_rock = document.querySelector('#rock');
var btn_paper = document.querySelector('#paper');
var btn_scissors = document.querySelector('#scissors');
var player_ch = document.querySelector("#player-ch");
var comp_ch = document.querySelector("#computer-ch");
var msg = document.querySelector("#message");
var computer_score = document.querySelector("#computer-score");
var player_score = document.querySelector("#player-score");


//generate random choice from array for computer choice
var myArray = ["✊", "🖐", "✌️"];

var computer_ch = '';
var user_ch = '';

var comp_score = 0
var user_score = 0

// change the player's hand by clicking the button and set the text of the player side
btn_rock.addEventListener('click', () => {

    // generate choice for computer every time user click the button and storing in computer_ch
    computer_ch = myArray[Math.floor(Math.random() * myArray.length)];

    // set the generated computer choice
    comp_ch.innerText = computer_ch;

    // set the user text same as btn rock (emoji)
    player_ch.innerText = btn_rock.innerText;

    // storing rock emoji in user_ch
    user_ch = btn_rock.innerText;

    //check for win 
    check_for_win(computer_ch, user_ch);
});


btn_paper.addEventListener('click', () => {
    // generate choice for computer every time user click the button
    computer_ch = myArray[Math.floor(Math.random() * myArray.length)];

    // set the generated computer choice
    comp_ch.innerText = computer_ch;

    // set the user text same as btn paper (emoji)
    player_ch.innerText = btn_paper.innerText;

    // storing paper emoji in user_ch
    user_ch = btn_paper.innerText;

    //check for win 
    check_for_win(computer_ch, user_ch);
});


btn_scissors.addEventListener('click', () => {
    // generate choice for computer every time user click the button
    computer_ch = myArray[Math.floor(Math.random() * myArray.length)];

    // set the generated computer choice
    comp_ch.innerText = computer_ch;

    // set the user text same as btn scissor (emoji)
    player_ch.innerText = btn_scissors.innerText;

    // storing scissors emoji in user_ch
    user_ch = btn_scissors.innerText;

    //check for win 
    check_for_win(computer_ch, user_ch);
});

// check for wining, this function call every time button clicked
// not declare the winner but increase scores according to condition
function check_for_win(computer_ch, user_ch) {
    // console.log(computer_ch, user_ch);
    if (user_ch == computer_ch) {
        // nothing 
        //set message 
        msg.classList.remove("text-success");
        msg.classList.remove("text-danger");
        msg.innerText = "Tie";
    }

    // guys we are comparing emojis XD

    else if (user_ch == "✊") {
        if (computer_ch == "🖐") {
            //set message 
            msg.innerText = "👉 You lose! Paper covers Rock";

            // add class accoding to message, here red becuase you lose
            // before that remove current class
            msg.classList.remove("text-success");
            msg.classList.add("text-danger");

            //computer wins, so increment computer's score
            computer_score.innerText = ++comp_score;


        }
        else {
            //set message 
            msg.innerHTML = "👉 You win! Rock smashes Scissors";

            // add class accoding to message, here red becuase you win
            // before that remove current class
            msg.classList.remove("text-danger");
            msg.classList.add("text-success");

            //player wins, so increment player's score
            player_score.innerText = ++user_score;
        }
    }

    else if (user_ch == "🖐") {
        if (computer_ch == "✌️") {
            //set message 
            msg.innerText = "👉 You lose! Scissor cut Paper";

            // add class accoding to message, here red becuase you lose
            // before that remove current class
            msg.classList.remove("text-success");
            msg.classList.add("text-danger");

            //computer wins, so increment computer's score
            computer_score.innerText = ++comp_score;


        }
        else {
            //set message 
            msg.innerHTML = "👉 You win! Paper covers Rock";

            // add class accoding to message, here red becuase you win
            // before that remove current class
            msg.classList.remove("text-danger");
            msg.classList.add("text-success");

            //player wins, so increment player's score
            player_score.innerText = ++user_score;
        }
    }

    else if (user_ch == "✌️") {
        if (computer_ch == "✊") {
            //set message 
            msg.innerText = "👉 You lose! Rock smashes Scissors";

            // add class accoding to message, here red becuase you lose
            // before that remove current class
            msg.classList.remove("text-success");
            msg.classList.add("text-danger");

            //computer wins, so increment computer's score
            computer_score.innerText = ++comp_score;


        }
        else {
            //set message 
            msg.innerHTML = "👉 You win! Scissor cut Paper";

            // add class accoding to message, here red becuase you win
            // before that remove current class
            msg.classList.remove("text-danger");
            msg.classList.add("text-success");

            //player wins, so increment player's score
            player_score.innerText = ++user_score;
        }
    }
    else {
        msg.innerHTML = ":(";
    }

}