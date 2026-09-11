/**
 * @param {number[]} digits
 * @return {number}
 */
var totalNumbers = function(digits) {
    const count = new Array(10).fill(0);
    for (const d of digits) {
        count[d]++;
    }

    let validCount = 0;

    // Loop through all 3-digit even numbers (100 to 998)
    for (let i = 100; i <= 998; i += 2) {
        const hunDigit = Math.floor(i / 100);
        const tensDigit = Math.floor(i / 10) % 10;
        const unitDigit = i % 10;

        const req = new Array(10).fill(0);
        req[hunDigit]++;
        req[tensDigit]++;
        req[unitDigit]++;

        let possible = true;
        for (let j = 0; j < 10; j++) {
            if (req[j] > count[j]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            validCount++;
        }
    }

    return validCount;
};