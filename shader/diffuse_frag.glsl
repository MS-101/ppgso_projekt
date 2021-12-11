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

//struktura pre pointLight
struct PointLight {
  vec3 position;

  float constant;
  float linear;
  float quadratic;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
};
#define NR_POINT_LIGHTS 3
uniform PointLight pointLights[NR_POINT_LIGHTS];

//vypocet pointlight
vec3 CalcPointLight(PointLight light, vec3 norm, vec3 FragPos, vec3 viewDir)
{
  vec3 lightDir = normalize(light.position - FragPos);
  float diffuseDir = max(dot(normal, vec4(normalize(LightDirection), 1.0f)), 0.0f);
  vec3 reflectDir = reflect(-LightDirection, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
  float distance    = length(light.position - FragPos);
  float attenuation = 1.0 / (light.constant + light.linear * distance +
  light.quadratic * (distance * distance));

  vec3 ambient  = light.ambient  * vec3(texture(Texture, vec2(texCoord.x, 1.0 - texCoord.y) + TextureOffset));
  vec3 diffuse  = light.diffuse  * diffuseDir *  vec3(texture(Texture, vec2(texCoord.x, 1.0 - texCoord.y) + TextureOffset));
  vec3 specular = light.specular * spec *  vec3(texture(Texture, vec2(texCoord.x, 1.0 - texCoord.y) + TextureOffset));
  ambient  *= attenuation;
  diffuse  *= attenuation;
  specular *= attenuation;
  return (ambient + diffuse + specular);
}


void main() {
  //directional light
  float diffuse = max(dot(normal, vec4(normalize(LightDirection), 1.0f)), 0.0f);
  vec3 viewDir = normalize(viewPos - FragPos);
  vec3 reflectDir = reflect(-LightDirection, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
  vec3 specular = specularStrength * spec * lightColor;
  vec3 ambient = ambientStrength * lightColor;

  vec3 result = (ambient + diffuse + specular);
  for(int i = 0; i < NR_POINT_LIGHTS; i++){
    result += CalcPointLight(pointLights[i], norm, FragPos, viewDir);
  }
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
