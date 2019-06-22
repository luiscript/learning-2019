import Cocoa

var str = "Hello, playground"

//simple values

//let for constants and var for variables

var myVariable = 42;
myVariable = 50;
let myConstant = 42;

let implicitInteger = 70;
let implicitDouble = 70.0;
let explicitDouble: Double = 70;

let label = "The width is ";
let width = 94;
let widthLabel = label + String(width);

let apples = 3;
let oranges = 3;
let appleSummary = "I have \(apples) apples.";
let orangeSummary = "I have \(oranges) oranges";
let fruitSummary = "I have \(apples + oranges) fruits";

let quotation = """
Even though there's whitespace to the left,
the actual lines aren't  indented.
Except for this line.
Double quotes (") can appear without being escaped.

I still have \(apples + oranges) pieces of fruit.
""";

//arrays

var shoppingList = ["catfish", "water", "tulips"];
shoppingList[1] = "bottle of water";

var occupations = [
    "Malcom": "Capitain",
    "Kaylee": "Mechanic",
];

occupations["Jayne"] = "Public Relations";

shoppingList.append("blue paint");
print(occupations);

let emptyArray = [String]();
let emptyDictionary = [String: Float]();

shoppingList = [];
occupations = [:];


//control flow












