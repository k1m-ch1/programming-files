document.addEventListener('DOMContentLoaded', function(){
  document.querySelector('h1').addEventListener('click', function(){
    let myData = fetch('https://restcountries.com/v3.1/currency/USD')
    .then(response => response.json())
    .then(data => {
      console.log(data);
      for (let i = 0; i < data.length; i++){
        console.log(data[i].name.common);
        console.log(data[i].name.official);
        let myImg = document.createElement('img');
        let myCaption = document.createElement('figcaption');
        let myFigure = document.createElement('figure');
        myCaption.innerHTML = data[i].name.official
        myImg.src = data[i].flags.png
        myFigure.append(myImg);
        myFigure.append(myCaption);
        myFigure.style.textAlign = "center";
        document.querySelector('div').append(myFigure);
      }
    });
  });
});
