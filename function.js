let slideidx = 0;
showSlide();

function showSlide() {
    let i;
    let slide = document.getElementsByClassName("myslides");
    for (i = 0; i < slide.length; i++) {
        slide[i].style.display = "none";
    }
    slideidx++;
    if (slideidx > slide.length) {
        slideidx = 1;
    }
    slide[slideidx - 1].style.display = "block";
    slide[slideidx - 1].classList.add("fade");
    setTimeout(showSlide, 3500);
}
