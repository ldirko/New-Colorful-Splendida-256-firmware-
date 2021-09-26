const uint8_t exp_gamma [256] PROGMEM = {
 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,
 1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
 1,   2,   2,   2,   2,   2,   2,   2,   2,   2,   3,   3,   3,   3,   3,
 4,   4,   4,   4,   4,   5,   5,   5,   5,   5,   6,   6,   6,   7,   7,
 7,   7,   8,   8,   8,   9,   9,   9,   10,  10,  10,  11,  11,  12,  12,
 12,  13,  13,  14,  14,  14,  15,  15,  16,  16,  17,  17,  18,  18,  19,
 19,  20,  20,  21,  21,  22,  23,  23,  24,  24,  25,  26,  26,  27,  28,
 28,  29,  30,  30,  31,  32,  32,  33,  34,  35,  35,  36,  37,  38,  39,
 39,  40,  41,  42,  43,  44,  44,  45,  46,  47,  48,  49,  50,  51,  52,
 53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63,  64,  65,  66,  67,
 68,  70,  71,  72,  73,  74,  75,  77,  78,  79,  80,  82,  83,  84,  85,
 87,  89,  91,  92,  93,  95,  96,  98,  99,  100, 101, 102, 105, 106, 108,
 109, 111, 112, 114, 115, 117, 118, 120, 121, 123, 125, 126, 128, 130, 131,
 133, 135, 136, 138, 140, 142, 143, 145, 147, 149, 151, 152, 154, 156, 158,
 160, 162, 164, 165, 167, 169, 171, 173, 175, 177, 179, 181, 183, 185, 187,
 190, 192, 194, 196, 198, 200, 202, 204, 207, 209, 211, 213, 216, 218, 220,
 222, 225, 227, 229, 232, 234, 236, 239, 241, 244, 246, 249, 251, 253, 254, 255
};

const uint8_t cos_wave [256] = {
 0,   0,   0,   0,   1,   1,   1,   2,   2,   3,   4,   5,   6,   6,   8,
 9,   10,  11,  12,  14,  15,  17,  18,  20,  22,  23,  25,  27,  29,  31,
 33,  35,  38,  40,  42,  45,  47,  49,  52,  54,  57,  60,  62,  65,  68,
 71,  73,  76,  79,  82,  85,  88,  91,  94,  97,  100, 103, 106, 109, 113,
 116, 119, 122, 125, 128, 131, 135, 138, 141, 144, 147, 150, 153, 156, 159,
 162, 165, 168, 171, 174, 177, 180, 183, 186, 189, 191, 194, 197, 199, 202,
 204, 207, 209, 212, 214, 216, 218, 221, 223, 225, 227, 229, 231, 232, 234,
 236, 238, 239, 241, 242, 243, 245, 246, 247, 248, 249, 250, 251, 252, 252,
 253, 253, 254, 254, 255, 255, 255, 255, 255, 255, 255, 255, 254, 254, 253,
 253, 252, 252, 251, 250, 249, 248, 247, 246, 245, 243, 242, 241, 239, 238,
 236, 234, 232, 231, 229, 227, 225, 223, 221, 218, 216, 214, 212, 209, 207,
 204, 202, 199, 197, 194, 191, 189, 186, 183, 180, 177, 174, 171, 168, 165,
 162, 159, 156, 153, 150, 147, 144, 141, 138, 135, 131, 128, 125, 122, 119,
 116, 113, 109, 106, 103, 100, 97,  94,  91,  88,  85,  82,  79,  76,  73,
 71,  68,  65,  62,  60,  57,  54,  52,  49,  47,  45,  42,  40,  38,  35,
 33,  31,  29,  27,  25,  23,  22,  20,  18,  17,  15,  14,  12,  11,  10,
 9,   8,   6,   6,   5,   4,   3,   2,   2,   1,   1,   1,   0,   0,   0, 0
};

static const uint16_t FibonPlanarTable [] PROGMEM ={  //20x20

  256, 256, 256, 256, 256, 256, 256, 256, 183, 205, 206, 207, 256, 256, 256, 256, 256, 256, 256, 256, 
  256, 256, 256, 256, 256, 182, 185, 184, 204, 256, 211, 210, 209, 208, 256, 256, 256, 256, 256, 256, 
  256, 256, 256, 256, 181, 186, 256, 203, 213, 212, 225, 226, 227, 228, 229, 230, 256, 256, 256, 256, 
  256, 256, 256, 159, 180, 187, 202, 214, 256, 224, 256, 238, 237, 236, 235, 234, 231, 256, 256, 256, 
  256, 256, 160, 179, 188, 256, 201, 215, 223, 240, 239, 247, 248, 249, 250, 251, 233, 232, 256, 256, 
  256, 158, 161, 178, 189, 200, 216, 222, 241, 256, 246, 256, 3, 4, 5, 6, 252, 253, 256, 256, 
  256, 157, 162, 177, 190, 199, 217, 221, 242, 245, 256, 2, 22, 21, 20, 19, 7, 8, 254, 256, 
  256, 156, 163, 176, 191, 198, 256, 218, 220, 244, 1, 23, 26, 27, 28, 256, 18, 256, 9, 255, 
  135, 155, 164, 175, 256, 192, 197, 256, 219, 243, 24, 25, 48, 47, 256, 29, 256, 17, 256, 10, 
  136, 154, 165, 256, 174, 256, 193, 196, 195, 256, 0, 49, 50, 51, 46, 256, 30, 256, 16, 11, 
  134, 137, 153, 166, 256, 173, 172, 194, 171, 256, 98, 74, 73, 72, 52, 45, 256, 31, 15, 12, 
  133, 138, 256, 152, 167, 168, 169, 170, 147, 146, 256, 97, 75, 256, 71, 53, 44, 32, 14, 256, 
  256, 132, 139, 256, 151, 150, 149, 148, 145, 123, 122, 99, 96, 76, 70, 54, 43, 33, 13, 256, 
  256, 111, 131, 140, 141, 142, 143, 144, 256, 124, 121, 100, 95, 77, 69, 55, 42, 34, 256, 256, 
  256, 256, 112, 130, 129, 256, 256, 256, 125, 256, 120, 101, 94, 78, 68, 56, 41, 35, 256, 256, 
  256, 256, 110, 113, 114, 128, 127, 126, 118, 119, 102, 256, 93, 79, 67, 57, 40, 36, 256, 256, 
  256, 256, 256, 109, 108, 115, 116, 117, 104, 103, 256, 92, 80, 66, 256, 58, 39, 256, 256, 256, 
  256, 256, 256, 256, 256, 107, 106, 105, 256, 90, 91, 81, 65, 256, 59, 38, 256, 256, 256, 256, 
  256, 256, 256, 256, 256, 86, 87, 88, 89, 83, 82, 64, 256, 60, 37, 256, 256, 256, 256, 256, 
  256, 256, 256, 256, 256, 256, 256, 85, 84, 62, 63, 256, 61, 256, 256, 256, 256, 256, 256, 256

};  

static const uint16_t FibonCilindrTable [] PROGMEM = {  // 45x11

85, 256, 256, 86, 256, 110, 256, 111, 256, 134, 256, 135, 256, 158, 256, 256, 159, 182, 256, 256, 183, 256, 207, 256, 208, 256, 231, 256, 232, 256, 255, 256, 256, 12, 13, 256, 256, 36, 256, 38, 37, 61, 256, 256, 62,
256, 88, 87, 108, 109, 256, 112, 132, 133, 256, 136, 156, 157, 256, 161, 160, 181, 256, 185, 184, 205, 206, 256, 209, 229, 230, 256, 233, 256, 254, 256, 10, 11, 14, 256, 34, 35, 256, 39, 256, 60, 256, 64, 63, 84,
89, 106, 107, 256, 114, 113, 131, 256, 138, 137, 155, 256, 163, 162, 179, 180, 256, 186, 203, 204, 256, 211, 210, 228, 256, 235, 234, 252, 253, 256, 9, 16, 15, 256, 33, 256, 41, 40, 58, 59, 256, 65, 82, 83, 256,
105, 256, 116, 115, 129, 130, 256, 139, 256, 154, 256, 164, 256, 178, 256, 188, 187, 202, 256, 256, 212, 226, 227, 256, 236, 256, 251, 256, 7, 8, 17, 256, 256, 32, 256, 42, 256, 57, 256, 67, 66, 81, 256, 91, 90,
256, 117, 256, 128, 256, 256, 140, 152, 153, 256, 165, 256, 177, 256, 189, 256, 201, 256, 214, 213, 225, 256, 256, 237, 249, 250, 256, 6, 256, 18, 256, 30, 31, 256, 43, 256, 56, 256, 68, 256, 80, 256, 92, 256, 104,
118, 256, 127, 256, 256, 141, 151, 256, 256, 166, 256, 176, 256, 190, 256, 200, 256, 215, 256, 224, 256, 256, 238, 248, 256, 256, 5, 256, 19, 256, 29, 256, 256, 44, 256, 55, 256, 69, 256, 79, 256, 93, 256, 103, 256,
256, 126, 256, 256, 142, 150, 256, 256, 167, 256, 175, 256, 191, 256, 199, 256, 216, 256, 223, 256, 256, 239, 247, 256, 256, 4, 256, 20, 256, 28, 256, 256, 45, 256, 54, 256, 70, 256, 78, 256, 94, 256, 102, 256, 119,
125, 256, 256, 143, 149, 256, 256, 168, 256, 174, 256, 192, 256, 198, 256, 217, 256, 222, 256, 256, 240, 246, 256, 256, 3, 256, 21, 256, 27, 256, 256, 46, 256, 53, 256, 71, 256, 77, 256, 95, 256, 101, 256, 120, 256,
256, 256, 144, 148, 256, 256, 169, 256, 173, 256, 193, 256, 197, 256, 218, 256, 221, 256, 256, 241, 245, 256, 256, 2, 256, 22, 256, 26, 256, 256, 47, 256, 52, 256, 72, 256, 76, 256, 96, 256, 100, 256, 121, 256, 124,
256, 145, 147, 256, 256, 170, 256, 172, 256, 194, 256, 196, 256, 219, 256, 220, 256, 256, 242, 244, 256, 256, 1, 256, 23, 256, 25, 256, 256, 48, 256, 51, 256, 73, 256, 75, 256, 97, 256, 99, 256, 122, 256, 123, 256,
146, 256, 256, 256, 256, 256, 171, 256, 256, 256, 195, 256, 256, 256, 256, 256, 256, 243, 256, 256, 256, 0, 256, 24, 256, 256, 256, 256, 49, 256, 50, 256, 256, 256, 74, 256, 256, 256, 98, 256, 256, 256, 256, 256, 256,


};

const uint8_t fibonacciToPhysical[] PROGMEM = { 

0, 98, 195, 49, 146, 243, 74, 171, 24, 122,
219, 50, 147, 244, 97, 194, 25, 123, 220, 73,
170, 1, 99, 196, 48, 145, 242, 75, 172, 23,
121, 218, 51, 148, 245, 96, 193, 26, 124, 221,
72, 169, 2, 100, 197, 47, 144, 241, 76, 173,
22, 120, 217, 52, 149, 246, 95, 192, 27, 125,
222, 71, 168, 3, 101, 198, 46, 143, 240, 77,
174, 21, 119, 216, 53, 150, 247, 94, 191, 28,
126, 223, 70, 167, 4, 102, 199, 45, 142, 239,
78, 175, 20, 118, 215, 54, 151, 248, 93, 190,
29, 127, 224, 69, 166, 5, 103, 200, 44, 141,
238, 79, 176, 19, 117, 214, 55, 152, 249, 92,
189, 30, 128, 225, 68, 165, 6, 104, 201, 43,
140, 237, 80, 177, 18, 116, 213, 56, 153, 250,
91, 188, 31, 129, 226, 67, 164, 7, 105, 202,
42, 139, 236, 81, 178, 17, 115, 212, 57, 154,
251, 90, 187, 32, 130, 227, 66, 163, 8, 106,
203, 41, 138, 235, 82, 179, 16, 114, 211, 58,
155, 252, 89, 186, 33, 131, 228, 65, 162, 9,
107, 204, 40, 137, 234, 83, 180, 15, 113, 210,
59, 156, 253, 88, 185, 34, 132, 229, 64, 161,
10, 108, 205, 39, 136, 233, 84, 181, 14, 112,
209, 60, 157, 254, 87, 184, 35, 133, 230, 63,
160, 11, 109, 206, 38, 135, 232, 85, 182, 13,
111, 208, 61, 158, 255, 86, 183, 36, 134, 231,
62, 159, 12, 110, 207, 37

};
