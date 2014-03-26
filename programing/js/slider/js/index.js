$(function () {

    var delay = 1000;
    var elem = $('.hide'); 
    function show(){
        var n = 0; 
        var length = elem.length;
        return function() {
            if(n === length) n = 0;
            elem.hide();
            $(elem[n++]).show();
        };
    }
    
    var s = show();
    var timer = setInterval(s, delay);

    elem
        .mouseover(function(){
            clearInterval(timer);
        })
        .mouseout(function(){
            timer = setInterval(s, delay);
        });
});
