#version 330
// A texture is expected as program attribute
uniform sampler2D Texture;

// Direction of light
uniform vec3 LightDirection;

// (optional) Transparency
uniform float Transparency;

// (optional) Texture offset
uniform vec2 TextureOffset;

// The vertex shader will feed this input
in vec2 texCoord;

// Wordspace normal passed from vertex shader
in vec4 normal;

// The final color
out vec4 FragmentColor;
float l;

float specularStrength = 0.5;
vec3 lightColor = {0.1,0.1,0.1};
uniform vec3 viewPos;
in vec3 FragPos;
float ambientStrength = 0.1;
in vec3 norm;

void main() {

  float diffuse = max(dot(normal, vec4(normalize(LightDirection), 1.0f)), 0.0f);
  vec3 viewDir = normalize(viewPos - FragPos);
  vec3 reflectDir = reflect(-LightDirection, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
  vec3 specular = specularStrength * spec * lightColor;
  vec3 ambient = ambientStrength * lightColor;

  vec3 result = (ambient + diffuse + specular);
  FragmentColor = texture(Texture, vec2(texCoord.x, 1.0 - texCoord.y) + TextureOffset) * vec4(result, 1.0);

  //FragmentColor = texture(Texture, vec2(texCoord.x, 1.0 - texCoord.y) + TextureOffset) * diffuse;

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
