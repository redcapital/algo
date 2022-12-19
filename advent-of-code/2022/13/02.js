const fs = require('fs');
const inp = fs.readFileSync(0);

const pp = console.log

function cmp(l1, l2) {
	const t1 = Array.isArray(l1);
	const t2 = Array.isArray(l2);
	if (!t1 && !t2) {
		return l1 - l2;
	}
	if (t1 && t2) {
		for (let i = 0;; i++) {
			if (i == l1.length && i == l2.length) {
				return 0;
			}
			if (i == l1.length) {
				return -1;
			}
			if (i == l2.length) {
				return 1;
			}
			const cv = cmp(l1[i], l2[i]);
			if (cv != 0) return cv;
		}
		pp("SHOULDNT REACH");
	}
	if (t1) {
		return cmp(l1, [l2]);
	}
	return cmp([l1], l2);
}

const lines = inp.toString().split("\n");
const packets  = [];
for (let i = 0; i < lines.length; i += 3) {
	const l1 = JSON.parse(lines[i]);
	const l2 = JSON.parse(lines[i + 1]);
	packets.push(l1);
	packets.push(l2);
}
pp(JSON.stringify([[2]]));
packets.push([[2]]);
packets.push([[6]]);
packets.sort(cmp);


let ans = 1;
for (let i = 0; i < packets.length; i++) {
	const j = JSON.stringify(packets[i]);
	if (j == '[[2]]' || j == '[[6]]') {
		ans *= (i + 1);
	}
}

pp(ans);
