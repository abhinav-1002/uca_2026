self.onmessage = (e) => {
    const users = e.data;

    if (!users || users.length === 0) {
        self.postMessage("No data found");
        self.close();
        return;
    }

    users.forEach(user => {
        console.log(`${user.firstName} - ${user.role}`);
    });

    self.postMessage("Task completed");
    self.close();
};