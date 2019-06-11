use std::mem;

fn main() {
    println!("Hello, world!");

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
