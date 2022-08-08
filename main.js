
document.addEventListener("DOMContentLoaded",()=>{
    const elementosCarrusel = document.querySelectorAll(".carousel");
    M.Carousel.init(elementosCarrusel,{
        duration: 150,
        dist: -80,
        shift: 5,
        padding: 5,
        indicators: true,
        numVisible: 3
    });
});

document.querySelector(".menu-btn").addEventListener("click" ,()=>{
    document.querySelector(".navegation-elements").classList.toggle("show");
});
var entero = true;
document.querySelector(".whole-plate").addEventListener("click",()=>{
    if(!entero){
        entero = true;
        document.querySelector(".whole-plate").classList.toggle("bg-whole-plate")
        document.querySelector(".middle-plate").classList.toggle("bg-middle-plate")
        document.querySelector(".menu-dish-txt-whole").classList.toggle("show-menu");
        document.querySelector(".menu-dish-txt-middle").classList.toggle("show-menu");
        
        document.querySelector(".menu-dish-txt-whole").classList.toggle("margin-bottom");
        document.querySelector(".menu-dish-txt-middle").classList.toggle("margin-bottom");
/*      
   document.querySelector(".menu-dish-txt-middle").classList.toggle("tamanio");
 */    }
});
document.querySelector(".middle-plate").addEventListener("click",()=>{
    if(entero){
        entero = false;
        document.querySelector(".whole-plate").classList.toggle("bg-whole-plate")
        document.querySelector(".middle-plate").classList.toggle("bg-middle-plate")
        document.querySelector(".menu-dish-txt-middle").classList.toggle("show-menu");
        document.querySelector(".menu-dish-txt-whole").classList.toggle("show-menu");
        
        document.querySelector(".menu-dish-txt-middle").classList.toggle("margin-bottom");
        document.querySelector(".menu-dish-txt-whole").classList.toggle("margin-bottom");
/*         document.querySelector(".menu-dish-txt-middle").classList.toggle("tamanio");
 */
    }
});