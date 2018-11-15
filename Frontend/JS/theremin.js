var context = new AudioContext(),
    mousedown = false,
    oscillator = null,
    gainNode = context.createGain();
    
    atmFrequency = 0;
    atmGain = 0;


document.body.addEventListener("mousedown", function (e) {
    mousedown = true;

    oscillator = context.createOscillator();
    oscillator.connect(gainNode);
    gainNode.connect(context.destination);

    calculateFrequencyAndGain(e);

    oscillator.start(context.currentTime);
});

document.body.addEventListener("mousemove", function (e) {
    if (mousedown) {
        calculateFrequencyAndGain(e);
    }
});

document.body.addEventListener("mouseup", function (e) {
    mousedown = false;
    if (oscillator) {
        oscillator.stop(context.currentTime);
        oscillator.disconnect();
    }
});

function calculateFrequencyAndGain(e) {
    var maxFrequency = 2000,
        minFrequency = 20,
        maxGain = 1,
        minGain = 0;

    //oscillator.frequency.value = ((e.clientX / window.innerWidth) * maxFrequency) + minFrequency;
    //gainNode.gain.value = 1 - ((e.clientY / window.innerHeight) * maxGain) + minGain;
    
    atmFrequency = oscillator.frequency.setTargetAtTime(((e.clientX / window.innerWidth) * maxFrequency) + minFrequency, context.currentTime, 0.01);
    atmGain = gainNode.gain.setTargetAtTime(1 - ((e.clientY / window.innerHeight) * maxGain) + minGain, context.currentTime, 0.01);
    console.log("atmFrequency");
    console.log("atmGain");
}

// for error handling when mouse leaves viewport
document.addEventListener("mouseleave", function (event) {

    if (event.clientY <= 0 || event.clientX <= 0 || (event.clientX >= window.innerWidth || event.clientY >= window.innerHeight)) {
        mousedown = false;
        if (oscillator) {
            oscillator.stop(context.currentTime);
            oscillator.disconnect();
        }
    }
});

function saveFrequencyAndGain(e){

    oscillator = context.createOscillator();
    oscillator.connect(gainNode);
    gainNode.connect(context.destination);

    oscillator.frequency.value = parseFloat(atmFrequency);
    console.log("hi");
    
    gainNode = 1 - parseFloat(atmGain);

    oscillator.start(context.currentTime);

    console.log(atmFrequency);
    console.log(atmGain);
    console.log("test");
}