

document.addEventListener('DOMContentLoaded', function() {

  // Use buttons to toggle between views
  document.querySelector('#inbox').addEventListener('click', () => load_mailbox('inbox'));
  document.querySelector('#sent').addEventListener('click', () => load_mailbox('sent'));
  document.querySelector('#archived').addEventListener('click', () => load_mailbox('archive'));
  document.querySelector('#compose').addEventListener('click', compose_email);

  // By default, load the inbox
  load_mailbox('inbox');
 
  document.addEventListener('click', event => {
    let element = event.target;
    if (element.id === 'email-bar'){
      fetch(`/emails/${element.dataset.id}`)
      .then(response => response.json())
      .then(data => {
        let reverseArchiveState = data.archived? "Unarchieve" :"Archive"
        document.querySelector('#emails-view').innerHTML = 
        `<hr>
        <div><b>From:</b>${data.sender}</div>
        <div><b>To:</b>${data.recipients}</div>
        <div><b>Subject:</b>${data.subject}</div>
        <div><b>Timestamp:</b>${data.timestamp}</div>
        <button id="reply" data-id="${data.id}" class="btn btn-sm btn-outline-primary">Reply</button>
        <button id="archive" data-id="${data.id}" class="btn btn-sm btn-outline-primary">${reverseArchiveState}</button>
        <hr>
        <p>
        ${data.body}
        </p>`
        fetch(`/emails/${data.id}`, {
          method: 'PUT',
          body: JSON.stringify({
            read: true
          })
        })
      })
    }
    else if (element.id === "reply"){
      console.log(element.dataset.id)
      fetch(`/emails/${element.dataset.id}`)
      .then(response => response.json())
      .then(data => {
      compose_email(data.sender);
      })
    }
    else if (element.id === "archive"){
      fetch(`/emails/${element.dataset.id}`)
      .then(response => response.json())
      .then(data => {
        console.log(data);
        fetch(`/emails/${data.id}`, {
          method: 'PUT',
          body: JSON.stringify({
            archived: !data.archived
          })
        })
        alert("Archived or Unarchived successfully! I advice you refresh to see the changes.");
      })
    }
  });
});

function compose_email(defaultDestination = '') {

  // Show compose view and hide other views
  document.querySelector('#emails-view').style.display = 'none';
  document.querySelector('#compose-view').style.display = 'block';

  // Clear out composition fields
  document.querySelector('#compose-recipients').value = defaultDestination;
  document.querySelector('#compose-subject').value = '';
  document.querySelector('#compose-body').value = '';
  document.querySelector('#compose-form').onsubmit = function() {
    // console.log(document.querySelector('#compose-subject').value);
    // console.log(document.querySelector('#compose-body').value);
    // console.log(document.querySelector('#compose-body').value);
    fetch('/emails', {
      method: 'POST',
      body: JSON.stringify({
          recipients: document.querySelector('#compose-recipients').value,
          subject: document.querySelector('#compose-subject').value,
          body: document.querySelector('#compose-body').value
      }
      )
    })
    .then(response => response.json())
    .then(result => {
        // Print result
        alert(result.message);
        console.log(result);
    });
  }
}

function load_mailbox(mailbox) {

  // Show the mailbox and hide other views
  document.querySelector('#emails-view').style.display = 'block';
  document.querySelector('#compose-view').style.display = 'none';

  // Show the mailbox name
  document.querySelector('#emails-view').innerHTML = `<h3>${mailbox.charAt(0).toUpperCase() + mailbox.slice(1)}</h3>`;
  fetch(`/emails/${mailbox}`)
  .then(response => response.json())
  .then(emails => {
    emails.forEach(function(email){
      let newElement = document.createElement('div');
      newElement.id = "email-bar";
      newElement.dataset.id = email.id;
      newElement.innerHTML = `<label class=\"details\"><b>${email.sender}</b> ${email.subject}</label><label class=\"date\">${email.timestamp}</label>`
      newElement.style.display = "flex";
      newElement.style.justifyContent = "space-between";
      newElement.style.border = "0.1rem solid black";
      newElement.style.padding = "3px 5px 3px 5px";
      document.querySelector('#emails-view').append(newElement);
    })
  })
}
