
/*
 *  initialize - called once when the program is started
 *  Creates audio sordeces and first gain and filter nodes
 */
function initialize(){
    for(let i = 0; i < sounds.length; i++){
        soundNodes[i] = context.createMediaElementSource(sounds[i]);
    }
    gainNodes[0] = context.createGain();
    filterNodes[0] = context.createBiquadFilter();

    filterNodes[0].connect(gainNodes[0]);
    gainNodes[0].connect(context.destination);
    
    isInitialized = true;
}

/*
 *  playSound() - plays the current sound depending on the 
 *                useres position on the y coordinate
 */

function playSound(){   
    for (var j = 0; j<15; j++){
        var y = j*30;
        if (yCoord > y && yCoord < y+30){
            let status = j;
            for (var i = 0; i < sounds.length; i++){
                if (i == status){     
                    if(!savedSounds.includes(i)){
                        soundNodes[i].connect(filterNodes[amountOfSavedElements]);
                        sounds[i].play();
                        sounds[i].loop = true;
                    }            
                    currentSound = i;
                } else if (!savedSounds.includes(i)){
                    sounds[i].pause();
                    sounds[i].currentTime = 0;
                }
            }
        }
    }
    
}

/*
 *  pauseSound - pauses all playing sound that are not 
 *                currently saved
 */
function pauseSounds(){
    for (var i = 0; i<sounds.length; i++){
        if(!savedSounds.includes(i)){
        sounds[i].pause();
        sounds[i].currentTime = 0;
        }
    }
}

/*
 *  setGain - changes the volume (gain) of the currently 
 *            playing sound depending on the users
 *            position on the x coordinate
 */
function setGain(){
    currentGain = 1 - (xCoord/630);
    gainNodes[amountOfSavedElements].gain.value = currentGain;
}

/*
 *  setFilterType - changes the type of the filter for the 
 *                  currently playing sound depending on the 
 *                  users choice of color
 */
function setFilterType(){
    switch(color){
        case 0: //nichts
            pauseSounds();
            colorString = "";
            break;
        case 1: //rot
            filterNodes[amountOfSavedElements].type = "allpass";
            colorString = "red";
            break;
        case 2: //blau
            filterNodes[amountOfSavedElements].type = "lowpass";
            colorString = "blue";
            break;
        case 3: //grün
            filterNodes[amountOfSavedElements].type = "highpass";
            colorString = "green";
            break;
    }
    currentFilter = filterNodes[amountOfSavedElements].type;
}

//FUNCTIONS FOR SAVING/DELETING SOUNDS

/*
 *  saveSounds - saves the currently playing sound
 *               creates new gain and filter nodes
 */
function saveSounds(){
    gainNodes[amountOfSavedElements].gain.value = currentGain;
    filterNodes[amountOfSavedElements].type = currentFilter;
    savedSounds[amountOfSavedElements] = currentSound;
    savePosition(colorString, xCoord, yCoord, amountOfSavedElements);

    amountOfSavedElements++;
    gainNodes[amountOfSavedElements] = context.createGain();
    filterNodes[amountOfSavedElements] = context.createBiquadFilter();

    filterNodes[amountOfSavedElements].connect(gainNodes[amountOfSavedElements]);
    gainNodes[amountOfSavedElements].connect(context.destination);
}

/*
 *  revertSavedSound - deletes the sound which was last saved
 */
function revertSavedSound(){
    savedSounds.splice((saveSounds.length-1), 1);
    savedPositions.splice((savedPositions.length - 1), 1);
    gainNodes.splice((gainNodes.length-1), 1);
    filterNodes.splice((filterNodes.length - 1), 1);
    amountOfSavedElements--;
}

/*
 *  clearSoundArray - deletes all saved sound
 */
function clearSoundArray(){
    while(!savedSounds.length == 0){
        savedSounds.splice((saveSounds.length - 1), 1);
        gainNodes.splice((gainNodes.length - 1), 1);
        filterNodes.splice((filterNodes.length - 1), 1);
        savedPositions.splice(savedPositions.length - 1, 1);
    }

    amountOfSavedElements = 0;
    
    canv.clearRect(0, 0, canv.width, canv.height);
}

// FUNCTIONS FOR DRAWING

/*
 *  drawPosition - draws a small mark on the canvas 
 *                 marking the useres current position
 */
function drawPosition(x,y){
    canv.clearRect(0, 0, canv.width, canv.height);

    canv.fillStyle = "black";

    if(x > 6 && y > 6) canv.fillRect((canv.width-x/(520/canv.width))+20, (y-6)*0.32, 10, 10);
}

/*
 *  savedPosition - saves the current position of the user
 *                  and color
 */
function savePosition(color, x, y, amountOfSavedElements){
    savedPositions[amountOfSavedElements] = new Array(color, x, y);
}

/*
 *  drawAllSavedPositions - draws all the currently saved
 *                          positions on the canves, with the color
 *                          of the users choice
 */
function drawAllSavedPositions(){
    for(let j = 0; j<savedPositions.length; j++){
        canv.fillStyle = savedPositions[j][0];
        canv.fillRect((canv.width-savedPositions[j][1]/(520/canv.width))+20, (savedPositions[j][2]-6)*0.32, 10, 10);
    }
}

/*
 *  startPlaying - calls all the functions needed to play sound
 *                 and to draw on the canvas
 */
function startPlaying(){
    if(!isInitialized) {
        initialize();
    }

    setGain();
    
    setFilterType();
    
    playSound();

    drawPosition(xCoord, yCoord);
    drawAllSavedPositions();
}