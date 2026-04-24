const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Instruction Generator</title>
<style>
    body {
        font-family: Arial, sans-serif;
    }
    .container {
        margin: 20px auto;
        width: 80%;
    }
    .form-group {
        margin-bottom: 10px;
    }
    .instruction-item {
        display: flex;
        justify-content: space-between;
        align-items: center;
        padding: 5px 10px;
        border: 1px solid #ccc;
        margin-bottom: 5px;
    }
    .instruction-item button {
        background-color: #f44336;
        color: white;
        border: none;
        padding: 5px 10px;
        cursor: pointer;
    }
</style>
</head>
<body>
<div class="container">
    <h2>Instruction Generator</h2>
    <div class="form-group">
        <label for="instruction-type">Instruction Type:</label>
        <select id="instruction-type">
            <option value="rotate">Rotate</option>
            <option value="move">Move</option>
        </select>
        <input type="number" id="instruction-value" placeholder="Enter value">
        <button onclick="addInstruction()">Add</button>
    </div>
    <div id="instruction-list"></div>
    <button onclick="submitInstructions()">Submit</button>
</div>

<script>
    var gateway = `ws://${window.location.hostname}/ws`;
    var websocket;
    window.addEventListener('load', onLoad);
    function initWebSocket() {
        console.log('Trying to open a WebSocket connection...');
        websocket = new WebSocket(gateway);
        websocket.onopen    = onOpen;
        websocket.onclose   = onClose;
        websocket.onmessage = onMessage; // <-- add this line    
    }
    function onOpen(event) {
        console.log('Connection opened');
    }
    function onClose(event) {
        console.log('Connection closed');
        setTimeout(initWebSocket, 2000);
    }
    function onMessage(event) {
            console.log(event.data)
    }
    function onLoad(event){
        initWebSocket();
    }
    let instructions = [];

    function addInstruction() {
        const type = document.getElementById('instruction-type').value;
        const value = parseFloat(document.getElementById('instruction-value').value);

        if (!isNaN(value)) {
            instructions.push([type, value]);
            renderInstructions();
        } else {
            alert('Please enter a valid number.');
        }
    }

    function renderInstructions() {
        const instructionList = document.getElementById('instruction-list');
        instructionList.innerHTML = '';
        instructions.forEach((instruction, index) => {
            const div = document.createElement('div');
            div.classList.add('instruction-item');
            div.innerHTML = `
                <span>${instruction[0]} ${instruction[1]}</span>
                <button onclick="deleteInstruction(${index})">Delete</button>
            `;
            instructionList.appendChild(div);
        });
    }

    function deleteInstruction(index) {
        instructions.splice(index, 1);
        renderInstructions();
    }

    function submitInstructions() {
        const jsonObject = { instructions: instructions, numInstructions: instructions.length };
        websocket.send(JSON.stringify(jsonObject))
        console.log(JSON.stringify(jsonObject));
    }
</script>
</body>
</html>
)rawliteral";