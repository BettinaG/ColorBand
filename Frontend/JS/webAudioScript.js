var mute = document.querySelector('.mute');
// Create an AudioContext instance for this sound
var audioContext = new window.AudioContext();
// Create a buffer for the incoming sound content
var source = audioContext.createBufferSource();
// Create the XHR which will grab the audio content
var request = new XMLHttpRequest();
// Create GainNode
var gainNode = audioContext.createGain();


function test(){
// Set the audio file src here
request.open('GET', '../Sounds/Elevation.mp3', true);
// Setting the responseType to arraybuffer sets up the audio decoding
request.responseType = 'arraybuffer';
request.onload = function() {
  // Decode the audio once the require is complete
  audioContext.decodeAudioData(request.response, function(buffer) {
    source.buffer = buffer;
    // Connect the audio to source (multiple audio buffers can be connected!)
    source.connect(audioContext.destination);
    // Simple setting for the buffer
    source.loop = true;
    // Change volume
    // Play the sound!
    source.start(0);
  },
   function(e) {
    console.log('Audio error! ', e);
  });
  console.log(gainNode.gain.value);
}
// Send the request which kicks off 
request.send();

// Connect the source to gainNode
source.connect(gainNode)
// Connect the gainNode to destination
gainNode.connect(audioContext.destination);

mute.onclick = voiceMute;

function voiceMute() {
  if(mute.id == "") {
    //gainNode.gain.setValueAtTime(0, audioContext.currentTime);
    gainNode.gain.value = 0;
    mute.id = "activated";
    mute.innerHTML = "Unmute";
    console.log(gainNode.gain.value);
  } else {
    gainNode.gain.setValueAtTime(1, audioContext.currentTime);
    mute.id = "";
    mute.innerHTML = "Mute";
    console.log(gainNode.gain.value);
  }
}
console.log(gainNode.gain.value);
document.getElementById("gainSlider").addEventListener("input", function(e){
  var gainValue = (this.value / 20);
  gainNode.gain.value = gainValue
  console.log(gainNode.gain.value);
})
}
