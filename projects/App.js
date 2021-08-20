// DEFINE YOUR FUNCTION BELOW
function sumArray(arr){
    for(i=1;i<arr.length;i++){
        arr[i]+=arr[i-1]
    }
    return arr[arr.length-1];
}

console.log(sumArray([2,3,4]))
