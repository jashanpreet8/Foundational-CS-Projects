document.addEventListener('DOMContentLoaded', function() {
    let mys = document.querySelector('.myself');
    mys.addEventListener('click', function() {
        mys.style.background = 'blue';
        document.querySelector('#my').innerHTML = 'I am a high school graduate';
    });
    let hob = document.querySelector('.hobbies');
    hob.addEventListener('click', function() {
        hob.style.background = '634857';
        document.querySelector('#ho').innerHTML = "I don't have many hobbies but I am interested in reading. hiking, robots(if that's a hobby).<br> I sort of like cleanliness and I like to make friends <br> but I can't act around fakes.";
    });
    let con = document.querySelector('.contact');
    con.addEventListener('click', function() {
        con.style.background = '8267f5';
        document.querySelector('#co').innerHTML = <i class="fa">&#xf0e0;</i>
    });
    let soc = document.querySelector('.socials');
    soc.addEventListener('click', function() {
        soc.style.background = '638e4a';
        document.querySelector('#so').innerHTML = <i class="fa">&#xf2ab;</i>
        document.querySelector('#so2').innerHTML = <i class="fab fa-instagram"></i>
    });
});