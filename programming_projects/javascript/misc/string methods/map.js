array = [2,3,4,8,12,43,895,34,4,12,9884]

function mul_by(multiplier){
  function mul_by_return(x, index){
    return x * multiplier
  }
  return mul_by_return
}

mul_by_two = mul_by(2)
// new_array = array.map(mul_by_two)

function def_and_log(x){
  x = x*2
  console.log(x)
}

new_array = array.forEach(def_and_log)