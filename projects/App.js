num=prompt("Guess the number:: ");
count=0;
do{
    count++;
    num=prompt("Guess the number:: ");
}while(num!==4)

console.log("It took "+count +" attempt.")
