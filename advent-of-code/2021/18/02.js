const fs = require('fs');
//const a = fs.readFileSync('input.txt').toString();
//console.log(a);
//process.exit(0);


let res = '';

function add(a, b) {
  return reduce(`[${a},${b}]`);
}

function reduce(a) {
  while (true) {
    let [a, done] = explode(a);
    if (done) continue;
    let [a, done] = split(a);
    if (done) continue;
  }
  return a;
}

function explode(a) {
  let c = 0;
  for (let i = 0; i < a.length; i++) {
    if (a[i] == '[') {
      c++;
      if (c == 5) {
        a = replace_right(a, find_closing(a, i + 1) + 1);
        a = replace_left(a, i - 1);
        return [a, true];
      }
    } else if (a[i] == ']') {
      c--;
    }
  }
  return [a, false];
}

function replace_right(s, p) {
  let i = p;
  let start = false, end = false;
  let num;
  while (i < s.length) {
    if (s[i] >= '0' && s[i] <= '9') {
      if (start === false) start = i; else end = i;
    } else {
      if (start !== false) break;
    }
  }
  return s.substr(0, start) + s.substr(end + 1);
}

function find_closing(s, p) {
  let c = 0;
  for (let i = p; i < a.length; i++) {
    if (a[i] == '[') c++;
    if (a[i] == ']') {
      c--;
      if (c < 0) return i;
    }
  }
}

fs.readFileSync('input.txt').toString().split(/\n/).forEach((line) => {
  line = line.trim();
  if (!line) return;
  if (!res) res = line; else res = add(res, line);
});

console.log(res);
