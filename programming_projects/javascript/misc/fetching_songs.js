async function checkSongArtist(songInput, artistInput) {
  let response = await fetch('https://soundslikethis.us/api/checkSongArtist', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({
      song: songInput,
      artist: artistInput
    })
  })
  return response.json();
}


async function getFeatures(songId) {
  let response = await fetch('https://soundslikethis.us/api/getFeatures', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({
      songId: songId
    })
  });
  return response.json();
}
async function getRec(songId, songFeatures, num) {
  const response = await fetch('https://soundslikethis.us/api/getRecs', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({
      songId1: songId,
      features: songFeatures,
      orig: songFeatures,
      num: num
    })
  });
  return response.json();
}

async function getRecDelta(origFeatures, recFeatures) {
  let response = await fetch('https://soundslikethis.us/api/getRecDelta', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({
      origFeatures: origFeatures, //make this smoother
      recFeatures: recFeatures
    })
  });
  return response.json();
}

let data = await checkSongArtist("Fe!n", "Travis Scott")
let songId = data.tracks.items[0].id;
console.log(songId);
let features = await getFeatures(songId);
console.log(features);
//let recDelta = await getRecDelta(features, features);
//console.log(recDelta);

let rec = await getRec(songId, features, 10);
console.log(rec);

