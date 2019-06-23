use std::mem;

const MEANING_OF_LIFE:u8 = 42; // no fixed address
static Z:i32 = 123;
static mut X:i32 = 456;

mod sh;

fn operators()
{
    //arithmetic
    let mut a =  2+3*4;
    println!("a = {}", a); 
    a = a+1; // -- o ++ no existen en rust
    println!("a = {}", a);
    a += 1;  // pero si exiten -= += *= /= %=
    println!("a = {}", a);

    println!("reminder of {} / {} = {}", a, 3, a%3);

    let a_cubed = i32::pow(a, 3);
    println!("{} cubed is {}", a, a_cubed);

    let b = 2.5;
    let b_cubed = f64::powi(b, 3);
    let b_to_pi = f64::powf(b, std::f64::consts::PI);

    println!("{} cubed = {}, {} ^ PI = {}", b, b_cubed, b, b_to_pi);


    // bitwise

    let c = 1 | 2;  // | OR  & AND  ^ XOR    ! NOR
    println!("1|2 = {}", c);

    let one_to_10 = 1 << 10;
    println!("2^10 = {}", one_to_10);


    //logical

    let pi_less_4 = std::f64::consts::PI < 4.0;
    println!("PI < 4 {}", pi_less_4);

    let x = 5;
    let x_is_5 = x == 5;

    println!("x == 5 {}", x_is_5);

}

fn basic_types()
{

    // inmutable unsigned 8 bits integer 0...255 
    let a:u8 = 123;  
    println!("a = {}", a);

    // mutable signed 8 bits integer
    let mut b:i8 = 0;
    println!("i = {}", b);
    b = 37;
    println!("i = {}", b);

    // 32 bits signed integer i32
    let mut c = 123456789; 
    println!("c = {}, size = {} bytes", c, mem::size_of_val(&c));
    c = -1;
    println!("c = {}, size = {} bytes", c, mem::size_of_val(&c));

    // i8 u8 i16 u 16 i32 u32 i64 u64

    let z:isize = 123;
    let size_of_z = mem::size_of_val(&z);
    println!("z = {}, takes up {} bytes, {}-bit os",
        z, size_of_z, size_of_z * 8);

    let d = 'x';
    println!("d = {}, size = {} bytes", d, mem::size_of_val(&d));

    let e = 2.5;
    println!("e = {}, size = {} bytes", e, mem::size_of_val(&e));

    let g = false;
    println!("g = {}, size = {} bytes", g, mem::size_of_val(&g));
}

fn scope_and_shadowing()
{
    let a = 123;
   
    {
        let b = 456;
        println!("inside, b = {}", b);

        let a = 789;
        println!("inside, a = {}", a);
    }
    //here b does not exists.
    //println!("outside, b = {}" ,b);
     println!("outside, a = {}", a);
}

fn if_statement(){
    let temp = 15;
    
    if temp > 30{
        println!("hot outside");
    } else if temp < 10{
        println!("really cold");
    }

    let day = if temp > 20 {"sunny"} else {"cloudy"};
    println!("today is {}", day);

    println!("is it {}", 
        if temp > 20 {"hot"} else if temp < 10 {"cold"} else {"ok"});
}

fn while_and_loop(){
    let mut x = 1;
    while x < 1000{
         x *= 2;
         if x == 64 { continue; }
         println!("x = {}",x);
    }

    let mut y = 1;
    loop{
        y *= 2;
        println!("y = {}", y);

        if y == 1 << 10 { break ; }
    }
}

fn for_loop(){
    for x in 1..11{
        if x == 3 { continue; }
        if x == 8 { break; }
        println!("x = {}", x);
    }

    for (pos, y) in (30..41).enumerate(){
        println!("{}: {}", pos, y);
    }
}

fn match_statement(){
    let country_code = 7;

    let country = match country_code{
        44 => "UK",
        46 => "Sweden",
        7 => "Russia",
        //_ => "unknown"
        1...999 => "unknown",
        _ => "invalid"
    };

    //range with ... includes corner cases here the range include 1 and 999

    println!("the country with code {} is {}", country_code, country);
}

struct Point{
    x: f64,
    y: f64
}

struct Line {
    start: Point,
    end: Point
}

fn structures(){
    let p = Point { x: 3.0, y: 4.0 };
    println!("point p is at ({},{})", p.x, p.y);

    let p2 = Point { x: 5.0, y: 10.0 };

    let myLine = Line { p, p2 };
}

fn main() {
    //println!("Hello, world!");
    //basic_types();
    //operators();
    //scope_and_shadowing();

    //mutable static problem
    // --> println!("{}", X);
    //you need to use unsafe
    // unsafe
    // {
    //     X = 789;
    //     println!("{}", X);
    // }

    //sh::stack_and_heap();

    //if_statement();
    //while_and_loop();
    //for_loop();

    //match_statement();

    structures();


}
