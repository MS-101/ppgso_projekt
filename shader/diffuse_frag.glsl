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
//premenna pre greyscale
float l;
//premenne pre vypocet directionLight
float specularStrength = 0.5;
vec3 lightColor = {0.1,0.1,0.1};
uniform vec3 viewPos;
in vec3 FragPos;
float ambientStrength = 0.1;
in vec3 norm;

float constant = 9.0f;
float linear = 0.5f;
float quadratic = 0.5f;

uniform vec3 position1 = {3, 3, 3};
uniform vec3 position2 = {-3, 3, 3};
uniform vec3 position3 = {0, 8, 0};
uniform vec3 positionSlnko = {-17,20,0};

vec3 ambient = {1.0f, 1.0f, 1.0f};
vec3 diffuse = {0.1f, 0.1f, 0.1f};
vec3 specular = {0.5f, 0.5f, 0.5f};

//vypocet pointlight
vec3 CalcPointLight(vec3 position, vec3 norm, vec3 FragPos, vec3 viewDir)
{
  vec3 lightDir = normalize(position - FragPos);
  float diffuseDir = max(dot(normal, vec4(normalize(lightDir), 1.0f)), 0.0f);
  vec3 reflectDir = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 5);
  float distance    = length(position - FragPos);
  float attenuation = 1.0 / (constant + linear * distance +
  quadratic * (distance * distance));

  vec3 ambient  = ambient  * vec3(texture(Texture, vec2(texCoord.x, 1.0 - texCoord.y) + TextureOffset));
  vec3 diffuse  = diffuse  * diffuseDir *  vec3(texture(Texture, vec2(texCoord.x, 1.0 - texCoord.y) + TextureOffset));
  vec3 specular = specular * spec *  vec3(texture(Texture, vec2(texCoord.x, 1.0 - texCoord.y) + TextureOffset));
  ambient  *= attenuation;
  diffuse  *= attenuation;
  specular *= attenuation;
  return (ambient + diffuse + specular);
}


void main() {
  //directional light
  vec3 lightDir = normalize(-LightDirection);
  float diffuse = max(dot(normal, vec4(normalize(lightDir), 1.0f)), 0.0f);
  vec3 viewDir = normalize(viewPos - FragPos);
  vec3 reflectDir = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 5);
  vec3 specular = specularStrength * spec * lightColor;
  vec3 ambient = ambientStrength * lightColor;

  vec3 result = (ambient + diffuse + specular);
  result += CalcPointLight(position1, norm, FragPos, viewDir);
  result += CalcPointLight(position2, norm, FragPos, viewDir);
  result += CalcPointLight(position3, norm, FragPos, viewDir);
  FragmentColor = texture(Texture, vec2(texCoord.x, 1.0 - texCoord.y) + TextureOffset) * vec4(result, 1.0);

  //greyscale
  //l = 0.3*FragmentColor.r + 0.59*FragmentColor.g + 0.11*FragmentColor.b;
  //FragmentColor.r = l;
  //FragmentColor.g = l;
  //FragmentColor.b = l;

  //convolution
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
