function loadContent(startAt){
  for(let i = startAt; i < startAt+10; i++){
    let newLabel = document.createElement('label')
    newLabel.style.backgroundColor = 'green';
    newLabel.style.marginTop = 10;
    newLabel.style.marginBottom = 10;
    newLabel.style.display = 'block';
    newLabel.style.fontSize = '64';
    newLabel.style.color = 'white';
    newLabel.style.textAlign = 'center';
    newLabel.innerHTML = `LABEL NUMBER ${i}`;
    document.querySelector('#content').append(newLabel);
  }
}

function logWindowInfo(){
  scrollYe = window.scrollY;
  height = window.innerHeight;
  width = window.innerWidth;
  screeny = window.screenY;
  offsetheight = document.body.offsetHeight;
  screenInfo = {
    scrollY: scrollYe,
    height: height,
    width: width,
    screeny: screeny,
    offsetheight: offsetheight
  }
  return screenInfo
}
let page = 1;

function loadContentAndUpdatePage(){
  loadContent(page);
  page+=10;
  console.log(logWindowInfo());
}

function fetchContentAndAdd(){
  let start = page;
  let end = start + 10 - 1;
  page = end + 1;
  fetch(`/new-content?start=${start}&end=${end}`)
  .then(response => response.json())
  .then(data => {
    data.posts.forEach(add_post)
  })
}

function add_post(contents){
  let newLabel = document.createElement('label')
  newLabel.style.backgroundColor = 'green';
  newLabel.style.marginTop = 10;
  newLabel.style.marginBottom = 10;
  newLabel.style.display = 'block';
  newLabel.style.fontSize = '64';
  newLabel.style.color = 'white';
  newLabel.style.textAlign = 'center';
  newLabel.innerHTML = contents;
  newLabel.className = 'post';
  document.querySelector('#content').append(newLabel);
}

document.addEventListener('DOMContentLoaded', function(){
  fetchContentAndAdd();
  document.addEventListener('click', function(){
    console.log(page);
    console.log(logWindowInfo());
  })
  window.onscroll = function(){
    if (window.innerHeight + window.scrollY >= document.body.offsetHeight){
      fetchContentAndAdd();
    }
  }
})