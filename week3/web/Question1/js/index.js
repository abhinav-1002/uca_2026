const url = "https://dummyjson.com/users";
const worker = new Worker("js/webworker.js");

async function getUserData() {
    try {
        const response = await fetch(url);

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        const data = await response.json();

        worker.postMessage(data.users || []);
    } catch (err) {
        console.error(err);
    }
}

getUserData();

worker.onmessage = (e) => {
    console.log(e.data);
};
