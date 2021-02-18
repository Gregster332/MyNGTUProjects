import UIKit

struct Phone: Identifiable {
    var brand: Brands
    var IMEINumber: Int
    var id: String {
        return String(IMEINumber)
    }
    var specifications: Specifications
}

enum Brands {
    case Apple
    case Samsung
    case Xiaomi
    case Honor
    case Pixel
    case RedMi
}

struct Specifications {
    var demensions: Demensions
    var weight: Double
    var OS: OS
    var processor: String
    var displayParametrs: Int
    var camera: String
}


struct Demensions {
    var height: Double
    var width: Double
}

enum OS {
    case IOS
    case Android
    case HarmonyOS
}



