const fields = [
    "First Name",
    "Last Name",
    "Email"
];

function generateForm() {
    return `
        <form>
            ${fields.map(field => `
                <label>${field}</label>
                <input type="text"><br><br>
            `).join("")}
        </form>
    `;
}

document.getElementById("form-container").innerHTML = generateForm();
