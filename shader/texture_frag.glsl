#version 330
// A texture is expected as program attribute
uniform sampler2D Texture;

// (optional) Transparency
uniform float Transparency;

// (optional) Texture offset
uniform vec2 TextureOffset;

// The vertex shader will feed this input
in vec2 texCoord;

// The final color
out vec4 FragmentColor;
float l;

void main() {
  FragmentColor = texture(Texture, vec2(texCoord.x, 1.0 - texCoord.y) + TextureOffset);
  FragmentColor.a = Transparency;

  //greyscale
  //l = 0.3*FragmentColor.r + 0.59*FragmentColor.g + 0.11*FragmentColor.b;
  //FragmentColor.r = l;
  //FragmentColor.g = l;
  //FragmentColor.b = l;

  //float[25] kernel = float[] (
  //0.0,  1.0,  1.0,  1.0, 1.0,
  //-1.0,  0.0,  1.0,  1.0, 1.0,
  //-1.0, -1.0,  0.0,  1.0, 1.0,
  //-1.0, -1.0, -1.0,  0.0, 1.0,
  //-1.0, -1.0, -1.0, -1.0, 0.0);
//
  //int index = 0;
  //vec4 color = vec4(0);
  //float factor = 1.0;
  //float bias = 0.0;
//
  //for (int i = -2; i <= 2; i++) {
  //  for (int j = -2; j <= 2; j++) {
  //    vec2 shift = vec2(i,j) / textureSize(Texture,0);
  //    color += kernel[index++] * texture(Texture, vec2(texCoord.x, 1.0 - texCoord.y) + shift);
  //  }
  //}
  //FragmentColor = color / factor + vec4(bias, bias, bias, 1);
}
