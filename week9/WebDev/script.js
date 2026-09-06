function NewPromise(executorFunction) {
    let state = "PENDING";
    let value = null;


    let successCallbacks = [];
    let failureCallbacks = [];

    function resolve(result) {
        if (state !== "PENDING") {
            return;
        }

        state = "FULFILLED";
        value = result;

        successCallbacks.forEach(callback => {
            callback(value);
        });

        successCallbacks = [];
        failureCallbacks = [];
    }

    function reject(error) {
        if (state !== "PENDING") {
            return;
        }

        state = "REJECTED";
        value = error;

        failureCallbacks.forEach(callback => {
            callback(value);
        });

        successCallbacks = [];
        failureCallbacks = [];
    }

    function then(fn) {
        return new NewPromise((resolve, reject) => {

            function handleSuccess(value) {
                try {
                    const result = fn(value);
                    resolve(result);
                } catch (error) {
                    reject(error);
                }
            }

            if (state === "FULFILLED") {
                handleSuccess(value);
            }
            else if (state === "PENDING") {
                successCallbacks.push(handleSuccess);
            }
        });
    }

    function customCatch(fn) {
        return new NewPromise((resolve, reject) => {

            function handleFailure(error) {
                try {
                    const result = fn(error);
                    resolve(result);
                } catch (err) {
                    reject(err);
                }
            }

            if (state === "REJECTED") {
                handleFailure(value);
            }
            else if (state === "PENDING") {
                failureCallbacks.push(handleFailure);
            }
        });
    }

    try {
        executorFunction(resolve, reject);
    } catch (error) {
        reject(error);
    }

    return {
        then,
        catch: customCatch
    };
}