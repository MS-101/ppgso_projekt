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
  // Lookup the color in Texture on coordinates given by texCoord
  // NOTE: Texture coordinate is inverted vertically for compatibility with OBJ
  FragmentColor = texture(Texture, vec2(texCoord.x, 1.0 - texCoord.y) + TextureOffset);
  FragmentColor.a = Transparency;

  l = 0.3*FragmentColor.r + 0.59*FragmentColor.g + 0.11*FragmentColor.b;
  FragmentColor.r = l;
  FragmentColor.g = l;
  FragmentColor.b = l;
}
