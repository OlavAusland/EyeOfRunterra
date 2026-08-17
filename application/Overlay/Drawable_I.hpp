#pragma once
#include <Shader.hpp>

class Drawable_I
{
protected:
    Shader m_shader;
public:
    Drawable_I();

    virtual void Draw() = 0;

    virtual ~Drawable_I() = default;
};
