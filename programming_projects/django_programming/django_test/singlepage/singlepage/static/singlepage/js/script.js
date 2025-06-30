window.onpopstate = function(event){
  showSection(event.state.section);
}

function showSection(pageNum){
  fetch(`/pages/${pageNum}`)
  .then(response => response.text())
  .then(data => document.querySelector('.content').innerHTML = data)
}

document.addEventListener('DOMContentLoaded', function(){
  document.querySelectorAll('button').forEach(function(button){
    button.onclick = function(){
      let section = this.dataset.page
      showSection(section);
      history.pushState({section:section}, '', `page${section}`)
    }
  })
})