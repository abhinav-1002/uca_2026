self.onmessage = (e) => {
    const users = e.data;

    if (!users || users.length === 0) {
        self.postMessage("No data found");
        self.close();
        return;
    }

    let data = users.map(user => {
        return {name:user.firstName,role:user.role}
    });

    self.postMessage(data);
    self.close();
};