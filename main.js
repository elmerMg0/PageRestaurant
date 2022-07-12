
document.addEventListener("DOMContentLoaded",()=>{
    const elementosCarrusel = document.querySelectorAll(".carousel");
    M.Carousel.init(elementosCarrusel,{
        duration: 150,
        dist: -100,
        shift: 5,
        padding: 5,
        indicators: true,
        numVisible: 3
    });
});

document.querySelector(".menu-btn").addEventListener("click" ,()=>{
    document.querySelector(".navegation-elements").classList.toggle("show");
});

