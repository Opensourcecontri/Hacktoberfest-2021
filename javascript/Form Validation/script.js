const btn = document.getElementById('btn');
const username = document.getElementById('username');
const email = document.getElementById('email');
const pass = document.getElementById('pass');
const vpass = document.getElementById('vpass');

let user = undefined;
let em = undefined;
let pas = undefined;
let vpas = undefined;

btn.addEventListener('click', e => {
    checkData();

    if (user !== true || em !== true || pas !== true || vpass !== true) {
        e.preventDefault();
    }
});


function checkData() {
    const usernameValue = username.value.trim();
    const emailValue = email.value.trim();
    const passwordValue = pass.value.trim();
    const vpasswordValue = vpass.value.trim();


    if (usernameValue === '') {
        setError(username, 'Username cannot be blank');
        user = false;
    }else{
        setNoError(username);
        user = true;
    }

    if (emailValue === '') {
        setError(email, 'Email cannot be blank');
        em = false;
    }else if (!rEmail(emailValue)) {
        setError(email, 'Email is not a valid');
        em = false;
    }else{
        setNoError(email);
        em = true;
    }

    if (passwordValue === '') {
        setError(pass, 'Password cannot be blank');
        pas = false;
    }else{
        setNoError(pass);
        pas = true;
    }

    if (vpasswordValue === '') {
        setError(vpass,'Password cannot be blank');
        vpas = false;
    } else if (passwordValue !== vpasswordValue) {
        setError(vpass, 'Password does not match');
        vpas = false;
    }else{
        setNoError(vpass);
        vpas = true;
    }

}

function setError(input, message) {
    const formLabel = input.parentElement;
    const small = formLabel.querySelector('small');
    formLabel.className = 'form-label error';
    small.innerText = message;
}

function setNoError(input) {
    const formLabel = input.parentElement;
    formLabel.className = 'form-label noerror';
}

function rEmail(email) {
    return /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/.test(email);
}