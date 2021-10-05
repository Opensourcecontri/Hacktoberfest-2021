var nodemailer = require('nodemailer')

var sender = nodemailer.createTransport({
    host: "",
    service: "",
    port: 587,
    secure: true,
    auth:{
        user: "",
        pass: ""
    }
})

var emailToSend = {
    from: "",
    to: "",
    subject: "",
    text: "",
}

sender.sendMail(emailToSend, (error) => {
    if (error){
        console.log(error)
    } else {
        console.log("Sucess on sending email")
    }
})