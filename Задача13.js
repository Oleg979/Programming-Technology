const reverse = n => {
  let res = [], idx = 1
  
  do res.unshift(n % 2 ? 1 : 0)
  while((n = Math.floor(n / 2)) > 0)
    
  return res.reduce((res, d) => {
    if (res != 0)idx *= 2
    return res + d * idx
  }, 0)
}

for(let i = 512; i <= 1024; i++)
  console.log(reverse(i))
