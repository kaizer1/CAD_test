module;


#ifdef _WIN32
#define _USE_MATH_DEFINES
#include <cmath>
#endif 


//import std;  // BIG ERROR ! 


export module lMath;


namespace losMath {

    export using lFloat = float;
    using lDouble = double;


    export class lv2
    {



    public:


        lv2() {
            x = 1.0f;
            y = 1.0f;
        }
        ~lv2() {
            x = 0.0f;
            y = 0.0f;
        }



        lv2(float a) {
            x = a;
            y = 0.0f;
        }
        lv2(float a, float b) {
            x = a;
            y = b;
        }

        lv2 operator*(lv2 v) {
            x = x * v.x;
            y = y * v.y;
            return *this;
        }

        lv2 operator*(float sca) {
            x = x * sca;
            y = y * sca;
            return *this;
        }

        lv2 operator+=(lv2 v) {
            x = x + v.x;
            y = y + v.y;
            return *this;
        }

        float dot(lv2& vec) {
            // float ssd;
            // ssd = x * vec.x + y * vec.y;

            return (x * vec.x + y * vec.y);
        }

        void getValue(const float& a, const float& b) {
            x = a;
            y = b;
        }





        float x;
        float y;

    };



    export class lv3
    {

    public:

        lv3() {
            x = 1.0f;
            y = 1.0f;
            z = 1.0f;
        }
        ~lv3() {
            x = 0;
            y = 0;
            z = 0;
        }

        lv3(float& vec);
        // LosVector3(LosVector3&& lVector);  // move constructor
        lv3(lv3& lVerr) {
            x = lVerr.x;
            y = lVerr.y;
            z = lVerr.z;
        }

        lv3(const lv3& lVerr) {
            x = lVerr.x;
            y = lVerr.y;
            z = lVerr.z;
        }

        // LosVector3(float& vec1, float& vec2, float& v3);

        lv3(float x1, float y1, float z1) {
            x = x1;
            y = y1;
            z = z1;
        }
        lv3(lv2 v2, float z1) {
            x = v2.x;
            y = v2.y;
            z = z1;
        }

        lv3 operator-(lv3& vec) {
            float xN, yN, zN;
            xN = x - vec.x;
            yN = y - vec.y;
            zN = z - vec.z;

            return lv3(xN, yN, zN);
        }

        lv3 operator+=(lv3& vec) {
            x = x + vec.x;
            y = y + vec.y;
            z = z + vec.z;

            return *this;
        }

        // void operator* (float scale);

        // LosVector3 operator=(const LosVector3& vec) const;

        lv3 normalized() {
            lv3 vectorBack;

            float squart = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

            if (squart == 0)
            {
                return vectorBack;
            }
            else
            {
                x = x / squart;
                y = y / squart;
                z = z / squart;

                return *this;
            }

        }
        lv3 cross(lv3& vec) {
            float a, b, c;
            a = (y * vec.z - vec.y * z);
            b = (x * vec.z - vec.x * z) * (-1);
            c = (x * vec.y - vec.x * y);
            x = a;
            y = b;
            z = c;
            return *this;

        }

        float dot(lv3& vec) {
            /*       float resultNumber;
                   resultNumber = x * vec3.x + y * vec3.y + z * vec3.z;*/

            return (x * vec.x + y * vec.y + z * vec.z);
        }

        void losSeeElement(lv3& vect) {

        }
        void losSeeElement() {

        }


        bool operator==(lv3& ver)
        {
            if (x != ver.x)
                return false;

            if (y != ver.y)
                return false;

            if (z != ver.z)
                return false;

            return true;
        }

        float x;
        float y;
        float z;

    private:



    };




    export class lv4
    {
    public:

        lv4() {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
            w = 0.0f;
        }

        ~lv4() {
            x = 0;
            y = 0;
            z = 0;
            w = 0;
        }

        lv4(const lv4& def) {
            x = def.x;
            y = def.y;
            z = def.z;
            w = def.w;
        }

        lv4(lv3 vec3) {
            x = vec3.x;
            y = vec3.y;
            z = vec3.z;
            w = 1.0f;
        }
        // LosVector4(LosVector3& vec3, float w);
        lv4(lv3 vec, float w1) {
            x = vec.x;
            y = vec.y;
            z = vec.z;
            w = w1;
        }
        lv4(float x1, float y1, float z1, float w1) {
            x = x1;
            y = y1;
            z = z1;
            w = w1;
        }
        lv4(float x1, float y1, float z1) {
            x = x1;
            y = y1;
            z = z1;
            w = 1.0f;
        }

        lv4(float x1, float y1) {
            x = x1;
            y = y1;
            z = 0.0f;
            w = 1.0f;
        }
        lv4(const float vec) {
            x = vec;
            y = vec;
            z = vec;
            w = vec;
        }

        lv4 operator-(lv4& vec) {
            x = x - vec.x;
            y = y - vec.y;
            z = z - vec.z;
            w = w - vec.w;

            return *this;
        }

        float x;
        float y;
        float z;
        float w;

    };



    export class lQ
    {
    public:

        lQ() {
            s = 1.0f;

            x = 1.0f;
            y = 1.0f;
            z = 1.0f;
        }
        ~lQ() {
            s = 0.0f;

            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }


        lQ(float e) {
            s = e;
            x = 1.0f;
            y = 1.0f;
            z = 1.0f;
        }
        lQ(float e, float q) {
            s = e;
            x = q;
            y = 1.0f;
            z = 1.0f;
        }
        lQ(float e, float q, float a) {
            s = e;

            x = q;
            y = a;
            z = 1.0f;
        }
        lQ(float e, float q, float a, float b) {
            s = e;
            x = q;
            y = a;
            z = b;
        }

        lQ(float s1, lv3 vec3) {
            s = s1;

            x = vec3.x;
            y = vec3.y;
            z = vec3.z;
        }




        float s;  // scalar

        float x;  // vector
        float y;
        float z;

    private:

    };


    /*   [0][0]  [1][0]  [2][0]
         [0][1]  [1][1]  [2][1]
         [0][2]  [1][2]  [2][2]   */


    export class lm33
    {
        friend class lQ;

    public:


        lm33() {

        }
        ~lm33() {

        }

        lm33(lv3 x, lv3 y, lv3 z) {
            this->elements[0][0] = x.x;    this->elements[1][0] = x.y;   this->elements[2][0] = x.z;
            this->elements[0][1] = y.x;    this->elements[1][1] = y.y;   this->elements[2][1] = y.z;
            this->elements[0][2] = z.x;    this->elements[1][2] = z.y;   this->elements[2][2] = z.z;
        }

        void rotateLosX(float angle) {
            lm33 rotateIdent = ident();

            rotateIdent.elements[1][1] = cosf(degrees_to_radian(angle));
            rotateIdent.elements[2][1] = sinf(degrees_to_radian(angle));
            rotateIdent.elements[1][2] = -sinf(degrees_to_radian(angle));
            rotateIdent.elements[2][2] = cosf(degrees_to_radian(angle));

            *this = *this * rotateIdent;
        }
        void rotateLosY(float angle) {
            lm33 rotateIdent = ident();

            rotateIdent.elements[0][0] = cosf(degrees_to_radian(angle));
            rotateIdent.elements[2][0] = -sinf(degrees_to_radian(angle));
            rotateIdent.elements[0][2] = sinf(degrees_to_radian(angle));
            rotateIdent.elements[2][2] = cosf(degrees_to_radian(angle));

            *this = *this * rotateIdent;
        }
        void rotateLosZ(float angle) {
            lm33 rotateIdent = ident();

            rotateIdent.elements[0][0] = cosf(degrees_to_radian(angle));
            rotateIdent.elements[1][0] = sinf(degrees_to_radian(angle));
            rotateIdent.elements[0][1] = -sinf(degrees_to_radian(angle));
            rotateIdent.elements[1][1] = cosf(degrees_to_radian(angle));

            *this = *this * rotateIdent;

        }

        lQ getRotationMatrix(lm33& rotMat) const {
            float t, s;

            t = 1.0f + rotMat.elements[0][0] + rotMat.elements[1][1] + rotMat.elements[2][2];

            if (t > FLT_EPSILON)
            {
                s = 0.5f / sqrtf(t);
                return lQ((rotMat.elements[2][1] - rotMat.elements[1][2]) * s,
                    (rotMat.elements[0][2] - rotMat.elements[2][0]) * s,
                    (rotMat.elements[1][0] - rotMat.elements[0][1]) * s,
                    0.25f / s);
            }
            else
            {
                if (rotMat.elements[0][0] > rotMat.elements[1][1] &&
                    rotMat.elements[0][0] > rotMat.elements[2][2])
                {
                    s = 0.5f / sqrtf(1.0f + rotMat.elements[0][0] - rotMat.elements[1][1] - rotMat.elements[2][2]);
                    return lQ(0.25f / s, (rotMat.elements[0][1] + rotMat.elements[1][0]) * s,
                        (rotMat.elements[0][2] + rotMat.elements[2][0]) * s,
                        (rotMat.elements[2][1] - rotMat.elements[1][2]) * s);
                }
                else if (rotMat.elements[1][1] > rotMat.elements[2][2])
                {
                    s = 0.5f / sqrtf(1.0f - rotMat.elements[0][0] + rotMat.elements[1][1] - rotMat.elements[2][2]);
                    return  lQ((rotMat.elements[0][1] + rotMat.elements[1][0]) * s,
                        0.25f / s,
                        (rotMat.elements[1][2] + rotMat.elements[2][1]) * s,
                        (rotMat.elements[0][2] - rotMat.elements[2][0]) * s);
                }
                else
                {
                    s = 0.5f / sqrtf(1.0f - rotMat.elements[0][0] - rotMat.elements[1][1] + rotMat.elements[2][2]);
                    return lQ((rotMat.elements[0][2] + rotMat.elements[2][0]) * s,
                        (rotMat.elements[1][2] + rotMat.elements[2][1]) * s,
                        0.25f / s,
                        (rotMat.elements[1][0] - rotMat.elements[0][1]) * s);
                }
            }
        }


        float elements[3][3];

        lm33 ident() {
            lm33 newM;

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j)
                    newM.elements[i][j] = 0.0f;
            }

            newM.elements[0][0] = 1.0f;
            newM.elements[1][1] = 1.0f;
            newM.elements[2][2] = 1.0f;

            return newM;
        }
        auto degrees_to_radian(double deg) -> double {
            return deg * M_PI / 180.0;
        }
        lm33 operator*(lm33& lMat) {
            lm33 returnM;

            /*  [0][0]  [1][0]  [2][0]
                [0][1]  [1][1]  [2][1]
                [0][2]  [1][2]  [2][2]   */

            returnM.elements[0][0] = this->elements[0][0] * lMat.elements[0][0] + this->elements[1][0] * lMat.elements[0][1] + this->elements[2][0] * lMat.elements[0][2];

            returnM.elements[1][0] = this->elements[0][0] * lMat.elements[1][0] + this->elements[1][0] * lMat.elements[1][1] + this->elements[2][0] * lMat.elements[1][2];

            returnM.elements[2][0] = this->elements[0][0] * lMat.elements[2][0] + this->elements[1][0] * lMat.elements[2][1] + this->elements[2][0] * lMat.elements[2][2];


            returnM.elements[0][1] = this->elements[0][1] * lMat.elements[0][0] + this->elements[1][1] * lMat.elements[0][1] + this->elements[2][1] * lMat.elements[0][2];

            returnM.elements[1][1] = this->elements[0][1] * lMat.elements[1][0] + this->elements[1][1] * lMat.elements[1][1] + this->elements[2][1] * lMat.elements[1][2];

            returnM.elements[2][1] = this->elements[0][1] * lMat.elements[2][0] + this->elements[1][1] * lMat.elements[2][1] + this->elements[2][1] * lMat.elements[2][2];


            returnM.elements[0][2] = this->elements[0][2] * lMat.elements[0][0] + this->elements[1][2] * lMat.elements[0][1] + this->elements[2][2] * lMat.elements[0][2];

            returnM.elements[1][2] = this->elements[0][2] * lMat.elements[1][0] + this->elements[1][2] * lMat.elements[1][1] + this->elements[2][2] * lMat.elements[1][2];

            returnM.elements[2][2] = this->elements[0][2] * lMat.elements[2][0] + this->elements[1][2] * lMat.elements[2][1] + this->elements[2][2] * lMat.elements[2][2];


            return returnM;
        }
        void retuIden() {
            *this = ident();
        }

    };



    template <typename T>
    float degrees_to_radian(T deg)
    {
        return static_cast<float>(deg * M_PI / 180.0f);
    }





    /*  [0][0]  [1][0]  [2][0]  [3][0]
        [0][1]  [1][1]  [2][1]  [3][1]
        [0][2]  [1][2]  [2][2]  [3][2]
        [0][3]  [1][3]  [2][3]  [3][3]    */


    export class lm44
    {

    public:


        lm44() {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    elements[i][j] = 0.0f;
                }
            }
        }

        ~lm44() {

        }

        lm44(lm44& mat) = default;
        lm44(const lm44& mat) = default;

        //LosMatrix4_4(float v = 1);
        lm44(lv3& vec1, lv3& vec2, lv3& vec3) {
            this->elements[0][0] = vec1.x;   this->elements[1][0] = vec1.y;   this->elements[2][0] = vec1.z;
            this->elements[0][1] = vec2.x;   this->elements[1][1] = vec2.y;   this->elements[2][1] = vec2.z;
            this->elements[0][2] = vec3.x;   this->elements[1][2] = vec3.y;   this->elements[2][2] = vec3.z;
            this->elements[0][3] = 0.0f;     this->elements[1][3] = 0.0f;     this->elements[2][3] = 0.0f;

            this->elements[3][0] = 0.0f;
            this->elements[3][1] = 0.0f;
            this->elements[3][2] = 0.0f;
            this->elements[3][3] = 1.0f;
        }
        lm44(lv3& vec1, lv3& vec2, lv3& vec3, lv3& vec4) {
            this->elements[0][0] = vec1.x;   this->elements[1][0] = vec1.y;   this->elements[2][0] = vec1.z;
            this->elements[0][1] = vec2.x;   this->elements[1][1] = vec2.y;   this->elements[2][1] = vec2.z;
            this->elements[0][2] = vec3.x;   this->elements[1][2] = vec3.y;   this->elements[2][2] = vec3.z;
            this->elements[0][3] = vec4.x;   this->elements[1][3] = vec4.y;   this->elements[2][3] = vec4.z;

            this->elements[3][0] = 0.0f;
            this->elements[3][1] = 0.0f;
            this->elements[3][2] = 0.0f;
            this->elements[3][3] = 1.0f;
        }

        lm44(lv4& vec1, lv4& vec2, lv4& vec3, lv4& vec4) {
            this->elements[0][0] = vec1.x;   this->elements[1][0] = vec1.y;   this->elements[2][0] = vec1.z; this->elements[3][0] = vec1.w;
            this->elements[0][1] = vec2.x;   this->elements[1][1] = vec2.y;   this->elements[2][1] = vec2.z;   this->elements[3][1] = vec2.w;
            this->elements[0][2] = vec3.x;   this->elements[1][2] = vec3.y;   this->elements[2][2] = vec3.z;    this->elements[3][2] = vec3.w;
            this->elements[0][3] = vec4.x;   this->elements[1][3] = vec4.y;   this->elements[2][3] = vec4.z;     this->elements[3][3] = vec4.w;
        }


        void ScaleLos(lv3 vecScale) {
            lm44 idena = iden();

            idena.elements[0][0] = vecScale.x;
            idena.elements[1][1] = vecScale.y;
            idena.elements[2][2] = vecScale.z;

            *this = *this * idena;
        }
        void Transposition(lv3 vecTransposition) {
            lm44 idena = iden();

            idena.elements[3][0] = vecTransposition.x;
            idena.elements[3][1] = vecTransposition.y;
            idena.elements[3][2] = vecTransposition.z;

            *this = *this * idena;
        }

        lm44 iden()
        {
            lm44 backMM;
            backMM.elements[0][0] = 1.0f;
            backMM.elements[0][1] = 0.0f;
            backMM.elements[0][2] = 0.0f;
            backMM.elements[0][3] = 0.0f;
            backMM.elements[1][0] = 0.0f;
            backMM.elements[1][1] = 1.0f;
            backMM.elements[1][2] = 0.0f;
            backMM.elements[1][3] = 0.0f;
            backMM.elements[2][0] = 0.0f;
            backMM.elements[2][1] = 0.0f;
            backMM.elements[2][2] = 1.0f;
            backMM.elements[2][3] = 0.0f;
            backMM.elements[3][0] = 0.0f;
            backMM.elements[3][1] = 0.0f;
            backMM.elements[3][2] = 0.0f;
            backMM.elements[3][3] = 1.0f;

            return backMM;
        }


        void rotateLosY(float angle) {
            lm44 rotateIdent = iden();

            rotateIdent.elements[0][0] = cosf(degrees_to_radian(angle));
            rotateIdent.elements[2][0] = -sinf(degrees_to_radian(angle));
            rotateIdent.elements[0][2] = sinf(degrees_to_radian(angle));
            rotateIdent.elements[2][2] = cosf(degrees_to_radian(angle));

            *this = *this * rotateIdent;
        }
        void rotateLosX(float angle) {
            lm44 rotateIdent = iden();

            rotateIdent.elements[1][1] = cosf(degrees_to_radian(angle));
            rotateIdent.elements[2][1] = sinf(degrees_to_radian(angle));
            rotateIdent.elements[1][2] = -sinf(degrees_to_radian(angle));
            rotateIdent.elements[2][2] = cosf(degrees_to_radian(angle));

            *this = *this * rotateIdent;
        }
        void rotateLosZ(float angle) {
            lm44 rotateIdent = iden();

            rotateIdent.elements[0][0] = cosf(degrees_to_radian(angle));
            rotateIdent.elements[1][0] = sinf(degrees_to_radian(angle));
            rotateIdent.elements[0][1] = -sinf(degrees_to_radian(angle));
            rotateIdent.elements[1][1] = cosf(degrees_to_radian(angle));

            *this = *this * rotateIdent;
        }

        void RotateWithOurAxilar(lv3 vec) {
            lm44 losBack = iden();
            losBack.Transposition(lv3(-vec.x, -vec.y, -vec.z));

            lm44 losBack1 = iden();
            losBack1.rotateLosY(180);

            lm44 losBack2 = iden();
            losBack.Transposition(lv3(vec.x, vec.y, vec.z));

            lm44 finalBack = losBack * losBack1 * losBack2;

            *this = *this * finalBack;

        }

        float elements[4][4];



        lm44 operator*(lm44 mat2) {
            lm44 backMatrix;

            // first row
            backMatrix.elements[0][0] = elements[0][0] * mat2.elements[0][0] + elements[1][0] * mat2.elements[0][1] + elements[2][0] * mat2.elements[0][2] + elements[3][0] * mat2.elements[0][3];
            backMatrix.elements[1][0] = elements[0][0] * mat2.elements[1][0] + elements[1][0] * mat2.elements[1][1] + elements[2][0] * mat2.elements[1][2] + elements[3][0] * mat2.elements[1][3];
            backMatrix.elements[2][0] = elements[0][0] * mat2.elements[2][0] + elements[1][0] * mat2.elements[2][1] + elements[2][0] * mat2.elements[2][2] + elements[3][0] * mat2.elements[2][3];
            backMatrix.elements[3][0] = elements[0][0] * mat2.elements[3][0] + elements[1][0] * mat2.elements[3][1] + elements[2][0] * mat2.elements[3][2] + elements[3][0] * mat2.elements[3][3];

            // second's row
            backMatrix.elements[0][1] = elements[0][1] * mat2.elements[0][0] + elements[1][1] * mat2.elements[0][1] + elements[2][1] * mat2.elements[0][2] + elements[3][1] * mat2.elements[0][3];
            backMatrix.elements[1][1] = elements[0][1] * mat2.elements[1][0] + elements[1][1] * mat2.elements[1][1] + elements[2][1] * mat2.elements[1][2] + elements[3][1] * mat2.elements[1][3];
            backMatrix.elements[2][1] = elements[0][1] * mat2.elements[2][0] + elements[1][1] * mat2.elements[2][1] + elements[2][1] * mat2.elements[2][2] + elements[3][1] * mat2.elements[2][3];
            backMatrix.elements[3][1] = elements[0][1] * mat2.elements[3][0] + elements[1][1] * mat2.elements[3][1] + elements[2][1] * mat2.elements[3][2] + elements[3][1] * mat2.elements[3][3];


            // third's row
            backMatrix.elements[0][2] = elements[0][2] * mat2.elements[0][0] + elements[1][2] * mat2.elements[0][1] + elements[2][2] * mat2.elements[0][2] + elements[3][2] * mat2.elements[0][3];
            backMatrix.elements[1][2] = elements[0][2] * mat2.elements[1][0] + elements[1][2] * mat2.elements[1][1] + elements[2][2] * mat2.elements[1][2] + elements[3][2] * mat2.elements[1][3];
            backMatrix.elements[2][2] = elements[0][2] * mat2.elements[2][0] + elements[1][2] * mat2.elements[2][1] + elements[2][2] * mat2.elements[2][2] + elements[3][2] * mat2.elements[2][3];
            backMatrix.elements[3][2] = elements[0][2] * mat2.elements[3][0] + elements[1][2] * mat2.elements[3][1] + elements[2][2] * mat2.elements[3][2] + elements[3][2] * mat2.elements[3][3];



            // four's row
            backMatrix.elements[0][3] = elements[0][3] * mat2.elements[0][0] + elements[1][3] * mat2.elements[0][1] + elements[2][3] * mat2.elements[0][2] + elements[3][3] * mat2.elements[0][3];
            backMatrix.elements[1][3] = elements[0][3] * mat2.elements[1][0] + elements[1][3] * mat2.elements[1][1] + elements[2][3] * mat2.elements[1][2] + elements[3][3] * mat2.elements[1][3];
            backMatrix.elements[2][3] = elements[0][3] * mat2.elements[2][0] + elements[1][3] * mat2.elements[2][1] + elements[2][3] * mat2.elements[2][2] + elements[3][3] * mat2.elements[2][3];
            backMatrix.elements[3][3] = elements[0][3] * mat2.elements[3][0] + elements[1][3] * mat2.elements[3][1] + elements[2][3] * mat2.elements[3][2] + elements[3][3] * mat2.elements[3][3];


            return backMatrix;
        }




    private:


    };








    export lm44 identity() {

        lm44 newa = lm44();
        newa.elements[0][0] = 1.0f;
        newa.elements[1][1] = 1.0f;
        newa.elements[2][2] = 1.0f;
        newa.elements[3][3] = 1.0f;
        return newa;
    }




    export template <typename T>
        lm44 perspectiveLosRithg(T FOV, T aspect, T near, T far) {
        T fovPreFinal = static_cast<float>(FOV * (3.14 / 180));

        T ymax = static_cast<T>(near * tan(fovPreFinal * 0.5));
        T ymin = -ymax;

        T  xmin = ymin * aspect;
        T  xmax = ymax * aspect;

        lm44 projectionMatrix = identity();

        projectionMatrix.elements[0][0] = static_cast<float> ((2.0 * near) / (xmax - xmin));
        projectionMatrix.elements[0][1] = 0.0f;
        projectionMatrix.elements[0][2] = 0.0f;
        projectionMatrix.elements[0][3] = 0.0f;

        projectionMatrix.elements[1][0] = 0.0f;
        projectionMatrix.elements[1][1] = static_cast<float>((2.0) * near / (ymax - ymin));
        projectionMatrix.elements[1][2] = 0.0f;
        projectionMatrix.elements[1][3] = 0.0f;

        projectionMatrix.elements[2][0] = (xmax + xmin) / (xmax - xmin);       // was 0.0f
        projectionMatrix.elements[2][1] = (ymax + ymin) / (ymax - ymin);       // was 0.0f
        projectionMatrix.elements[2][2] = -(far + near) / (far - near);
        projectionMatrix.elements[2][3] = -1.0f;

        projectionMatrix.elements[3][0] = 0.0f;
        projectionMatrix.elements[3][1] = 0.0f;
        projectionMatrix.elements[3][2] = -(2.0f * far * near) / (far - near);
        projectionMatrix.elements[3][3] = 0.0f;
        return projectionMatrix;
    }
    export lm44 LookAt_RightLos(lv3 eye, lv3 center, lv3 up, lm44& mat) {
        lv3 f, s, u;

        f = center - eye;
        f.normalized();   // my f theis view

        s = f;
        s.cross(up);
        s.normalized();  // my s theis right

        u = s;
        u.cross(f);     // my u theis viewUp

        lm44 backMatrix = identity();

        backMatrix.elements[0][0] = s.x;
        backMatrix.elements[1][0] = s.y;
        backMatrix.elements[2][0] = s.z;

        backMatrix.elements[0][1] = u.x;
        backMatrix.elements[1][1] = u.y;
        backMatrix.elements[2][1] = u.z;

        backMatrix.elements[0][2] = -f.x;
        backMatrix.elements[1][2] = -f.y;
        backMatrix.elements[2][2] = -f.z;

        backMatrix.elements[3][0] = -s.dot(eye);
        backMatrix.elements[3][1] = -u.dot(eye);
        backMatrix.elements[3][2] = f.dot(eye);

        backMatrix.elements[0][3] = 0.0f;
        backMatrix.elements[1][3] = 0.0f;
        backMatrix.elements[2][3] = 0.0f;
        backMatrix.elements[3][3] = 1.0f;


        lm33 losMatrix;

        losMatrix.elements[0][0] = s.x;
        losMatrix.elements[0][1] = s.y;
        losMatrix.elements[0][2] = s.z;

        losMatrix.elements[1][0] = u.x;
        losMatrix.elements[1][1] = u.y;
        losMatrix.elements[1][2] = u.z;

        losMatrix.elements[2][0] = -f.x;
        losMatrix.elements[2][1] = -f.y;
        losMatrix.elements[2][2] = -f.z;


        mat.elements[0][0] = losMatrix.elements[0][0];
        mat.elements[0][1] = losMatrix.elements[0][1];
        mat.elements[0][2] = losMatrix.elements[0][2];
        mat.elements[0][3] = 0.0f;                          // ???  was 0 and (0,3) = eye.x
        mat.elements[1][0] = losMatrix.elements[1][0];
        mat.elements[1][1] = losMatrix.elements[1][1];
        mat.elements[1][2] = losMatrix.elements[1][2];
        mat.elements[1][3] = 0.0f;                         // ??? example Math essentions 08-Picking
        mat.elements[2][0] = losMatrix.elements[2][0];
        mat.elements[2][1] = losMatrix.elements[2][1];
        mat.elements[2][2] = losMatrix.elements[2][2];
        mat.elements[2][3] = 0.0f;                        // ???  // correct I corrected
        mat.elements[3][0] = eye.x;
        mat.elements[3][1] = eye.y;
        mat.elements[3][2] = eye.z;
        mat.elements[3][3] = 1;


        return backMatrix;

    }


    void losSeeMatrixElements(lm44 mat) {
        // print each elemetns 
    }

    //lm44 operator*(lm44 mat1, lm44 mat2) {
    //    lm44 backMatrix;

    //    // first row
    //    backMatrix.elements[0][0] = mat1.elements[0][0] * mat2.elements[0][0] + mat1.elements[1][0] * mat2.elements[0][1] + mat1.elements[2][0] * mat2.elements[0][2] + mat1.elements[3][0] * mat2.elements[0][3];
    //    backMatrix.elements[1][0] = mat1.elements[0][0] * mat2.elements[1][0] + mat1.elements[1][0] * mat2.elements[1][1] + mat1.elements[2][0] * mat2.elements[1][2] + mat1.elements[3][0] * mat2.elements[1][3];
    //    backMatrix.elements[2][0] = mat1.elements[0][0] * mat2.elements[2][0] + mat1.elements[1][0] * mat2.elements[2][1] + mat1.elements[2][0] * mat2.elements[2][2] + mat1.elements[3][0] * mat2.elements[2][3];
    //    backMatrix.elements[3][0] = mat1.elements[0][0] * mat2.elements[3][0] + mat1.elements[1][0] * mat2.elements[3][1] + mat1.elements[2][0] * mat2.elements[3][2] + mat1.elements[3][0] * mat2.elements[3][3];

    //    // second's row
    //    backMatrix.elements[0][1] = mat1.elements[0][1] * mat2.elements[0][0] + mat1.elements[1][1] * mat2.elements[0][1] + mat1.elements[2][1] * mat2.elements[0][2] + mat1.elements[3][1] * mat2.elements[0][3];

    //    backMatrix.elements[1][1] = mat1.elements[0][1] * mat2.elements[1][0] + mat1.elements[1][1] * mat2.elements[1][1] + mat1.elements[2][1] * mat2.elements[1][2] + mat1.elements[3][1] * mat2.elements[1][3];

    //    backMatrix.elements[2][1] = mat1.elements[0][1] * mat2.elements[2][0] + mat1.elements[1][1] * mat2.elements[2][1] + mat1.elements[2][1] * mat2.elements[2][2] + mat1.elements[3][1] * mat2.elements[2][3];

    //    backMatrix.elements[3][1] = mat1.elements[0][1] * mat2.elements[3][0] + mat1.elements[1][1] * mat2.elements[3][1] + mat1.elements[2][1] * mat2.elements[3][2] + mat1.elements[3][1] * mat2.elements[3][3];


    //    // third's row
    //    backMatrix.elements[0][2] = mat1.elements[0][2] * mat2.elements[0][0] + mat1.elements[1][2] * mat2.elements[0][1] + mat1.elements[2][2] * mat2.elements[0][2] + mat1.elements[3][2] * mat2.elements[0][3];

    //    backMatrix.elements[1][2] = mat1.elements[0][2] * mat2.elements[1][0] + mat1.elements[1][2] * mat2.elements[1][1] + mat1.elements[2][2] * mat2.elements[1][2] + mat1.elements[3][2] * mat2.elements[1][3];

    //    backMatrix.elements[2][2] = mat1.elements[0][2] * mat2.elements[2][0] + mat1.elements[1][2] * mat2.elements[2][1] + mat1.elements[2][2] * mat2.elements[2][2] + mat1.elements[3][2] * mat2.elements[2][3];

    //    backMatrix.elements[3][2] = mat1.elements[0][2] * mat2.elements[3][0] + mat1.elements[1][2] * mat2.elements[3][1] + mat1.elements[2][2] * mat2.elements[3][2] + mat1.elements[3][2] * mat2.elements[3][3];



    //    // four's row
    //    backMatrix.elements[0][3] = mat1.elements[0][3] * mat2.elements[0][0] + mat1.elements[1][3] * mat2.elements[0][1] + mat1.elements[2][3] * mat2.elements[0][2] + mat1.elements[3][3] * mat2.elements[0][3];

    //    backMatrix.elements[1][3] = mat1.elements[0][3] * mat2.elements[1][0] + mat1.elements[1][3] * mat2.elements[1][1] + mat1.elements[2][3] * mat2.elements[1][2] + mat1.elements[3][3] * mat2.elements[1][3];

    //    backMatrix.elements[2][3] = mat1.elements[0][3] * mat2.elements[2][0] + mat1.elements[1][3] * mat2.elements[2][1] + mat1.elements[2][3] * mat2.elements[2][2] + mat1.elements[3][3] * mat2.elements[2][3];

    //    backMatrix.elements[3][3] = mat1.elements[0][3] * mat2.elements[3][0] + mat1.elements[1][3] * mat2.elements[3][1] + mat1.elements[2][3] * mat2.elements[3][2] + mat1.elements[3][3] * mat2.elements[3][3];


    //    return backMatrix;
    //}



    auto operator/(lv2 v1, lv2 v2) -> lv2 {
        return lv2(v1.x / v2.x, v1.y / v2.y);
    }

    auto operator/(lv2 v1, float v2) -> lv2 {
        return lv2(v1.x / v2, v1.y / v2);
    }


    export auto operator+(lv2 v1, lv2 v2) -> lv2 {
        return lv2(v1.x + v2.x, v1.y + v2.y);
    }

    export auto operator-(lv2 v1, lv2 v2) -> lv2 {
        return lv2(v1.x - v2.x, v1.y - v2.y);
    }


    export auto operator*(lv3 vec, float sca) -> lv3 {
        return lv3(vec.x * sca, vec.y * sca, vec.z * sca);
    }

    export auto operator*(lv3 vec, lv3 vec2) -> lv3 {
        float x1 = vec.y * vec2.z - vec.z * vec2.y;
        float x2 = vec.x * vec2.z - vec.z * vec2.x;
        float x3 = vec.x * vec2.y - vec.y * vec2.x;

        return lv3(x1, x2, x3);
    }

    auto operator+(lv3 vec, lv3 vec2) -> lv3 {
        return lv3(vec.x + vec2.x, vec.y + vec2.y, vec.z + vec2.z);
    }
    export auto  minVec3(lv3& vec, lv3& vec2) -> lv3 {
        float a, b, c;


        a = (/* DISABLES CODE */ (vec.x) < vec2.x) ? vec.x : vec2.x;
        b = (/* DISABLES CODE */ (vec.y) < vec2.y) ? vec.y : vec2.y;
        c = (/* DISABLES CODE */ (vec.z) < vec2.z) ? vec.z : vec2.z;

        // printf(" gg88  == %f %f and %f \n", a, b, c);

        return lv3(a, b, c);
    }
    export inline auto maxVec3(lv3& vec, lv3& vec2) -> lv3 {
        float a, b, c;


        a = (/* DISABLES CODE */ (vec.x) > vec2.x) ? vec.x : vec2.x;
        b = (/* DISABLES CODE */ (vec.y) > vec2.y) ? vec.y : vec2.y;
        c = (/* DISABLES CODE */ (vec.z) > vec2.z) ? vec.z : vec2.z;

        // printf(" gg88 max == %f %f and %f \n", a, b, c);

        return lv3(a, b, c);
    }


    export lQ operator*(lQ qu1, lQ qu2) {
        lv3 b1(qu1.x, qu1.y, qu1.z);
        lv3 b2(qu2.x, qu2.y, qu2.z);

        float aElement = (qu1.x * qu2.x) - b1.dot(b2);
        lv3 ass = b2 * qu1.x;
        lv3 wee = b1 * qu2.x;  // a qu2.x * b1 - not work&&& !
        return lQ(aElement, ass + wee + b1.cross(b2));
    }


    export lm44 backMatrixLosQuater(lQ& quater) {
        lm44 serBack = identity();

        //    float sx = quater.x * quater.x,
        //    sy = quater.y * quater.y,
        //    sz = quater.z * quater.z,
        //  //  sw = quater.w * quater.w,
        //    inv = 1.0f / (sx + sy + sz + sw);
        //
        //    serBack.elements[0][0] = (sx - sy - sz + sw) * inv;
        //    serBack.elements[1][1] = ( -sx + sy - sz + sw) * inv;
        //    serBack.elements[2][2] = ( -sx - sy + sz + sw) * inv;
        //    inv *= 2.0f;
        //
        //    float t1 = quater.x * quater.y;
        //   // float t2 = quater.z * quater.w;
        //
        //    serBack.elements[1][0] = (t1 + t2) * inv;
        //    serBack.elements[0][1] = (t1 - t2) * inv;
        //
        //    t1 = quater.x * quater.z;
        //   // t2 = quater.y * quater.w;
        //
        //    serBack.elements[2][0] = (t1 - t2) * inv;
        //    serBack.elements[0][2] = (t1 + t2) * inv;
        //
        //    t1 = quater.y * quater.z;
        //    t2 = quater.x * quater.w;
        //    serBack.elements[2][1] = (t1 + t2) * inv;
        //    serBack.elements[1][2] = (t1 - t2) * inv;

        return serBack;
    }

    lv4 operator*(lm44 mat, lv4 lvec) {
        lv4 returnVec;

        returnVec.x = lvec.x * mat.elements[0][0] + lvec.y * mat.elements[0][1] + lvec.z * mat.elements[0][2] + lvec.w * mat.elements[0][3];
        returnVec.y = lvec.x * mat.elements[1][0] + lvec.y * mat.elements[1][1] + lvec.z * mat.elements[1][2] + lvec.w * mat.elements[1][3];
        returnVec.z = lvec.x * mat.elements[2][0] + lvec.y * mat.elements[2][1] + lvec.z * mat.elements[2][2] + lvec.w * mat.elements[2][3];
        returnVec.w = lvec.x * mat.elements[3][0] + lvec.y * mat.elements[3][1] + lvec.z * mat.elements[3][2] + lvec.w * mat.elements[3][3];

        return returnVec;
    }

    export lv4 operator*(lv4 lvec, lm44 mat) {
        lv4 retVec;

        retVec.x = mat.elements[0][0] * lvec.x + mat.elements[1][0] * lvec.y + mat.elements[2][0] * lvec.z + mat.elements[3][0] * lvec.w;
        retVec.y = mat.elements[0][1] * lvec.x + mat.elements[1][1] * lvec.y + mat.elements[2][1] * lvec.z + mat.elements[3][1] * lvec.w;
        retVec.z = mat.elements[0][2] * lvec.x + mat.elements[1][2] * lvec.y + mat.elements[2][2] * lvec.z + mat.elements[3][2] * lvec.w;
        retVec.w = mat.elements[0][3] * lvec.x + mat.elements[1][3] * lvec.y + mat.elements[2][3] * lvec.z + mat.elements[3][3] * lvec.w;

        return retVec;
    }

    lv3 cross(lv3& v1, lv3& v2) {
        lv3 backV;

        backV.x = (v1.y * v2.z - v2.y * v1.z);
        backV.y = (v1.x * v2.z - v2.x * v1.z);
        backV.z = (v1.x * v2.y - v2.x * v1.y);

        return backV;
    }


    export lm44 operator*(lm44 mat, float s_var) {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                mat.elements[i][j] = mat.elements[i][j] * s_var;
        }

        return mat;
    }


    export lm44 inverse(lm44 mat) {
        float a0 = mat.elements[0][0] * mat.elements[1][1] - mat.elements[0][1] * mat.elements[1][0];
        float a1 = mat.elements[0][0] * mat.elements[1][2] - mat.elements[0][2] * mat.elements[1][0];
        float a2 = mat.elements[0][0] * mat.elements[1][3] - mat.elements[0][3] * mat.elements[1][0];
        float a3 = mat.elements[0][1] * mat.elements[1][2] - mat.elements[0][2] * mat.elements[1][1];
        float a4 = mat.elements[0][1] * mat.elements[1][3] - mat.elements[0][3] * mat.elements[1][1];
        float a5 = mat.elements[0][2] * mat.elements[1][3] - mat.elements[0][3] * mat.elements[1][2];

        float b0 = mat.elements[2][0] * mat.elements[3][1] - mat.elements[2][1] * mat.elements[3][0];
        float b1 = mat.elements[2][0] * mat.elements[3][2] - mat.elements[2][2] * mat.elements[3][0];
        float b2 = mat.elements[2][0] * mat.elements[3][3] - mat.elements[2][3] * mat.elements[3][0];
        float b3 = mat.elements[2][1] * mat.elements[3][2] - mat.elements[2][2] * mat.elements[3][1];
        float b4 = mat.elements[2][1] * mat.elements[3][3] - mat.elements[2][3] * mat.elements[3][1];
        float b5 = mat.elements[2][2] * mat.elements[3][3] - mat.elements[2][3] * mat.elements[3][2];

        float det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
        float inv_det = 1.0f / det;


        lm44 inv = identity();
        inv.elements[0][0] = +mat.elements[1][1] * b5 - mat.elements[1][2] * b4 + mat.elements[1][3] * b3;
        inv.elements[1][0] = -mat.elements[1][0] * b5 + mat.elements[1][2] * b2 - mat.elements[1][3] * b1;
        inv.elements[2][0] = +mat.elements[1][0] * b4 - mat.elements[1][1] * b2 + mat.elements[1][3] * b0;
        inv.elements[3][0] = -mat.elements[1][0] * b3 + mat.elements[1][1] * b1 - mat.elements[1][2] * b0;
        inv.elements[0][1] = -mat.elements[0][1] * b5 + mat.elements[0][2] * b4 - mat.elements[0][3] * b3;
        inv.elements[1][1] = +mat.elements[0][0] * b5 - mat.elements[0][2] * b2 + mat.elements[0][3] * b1;
        inv.elements[2][1] = -mat.elements[0][0] * b4 + mat.elements[0][1] * b2 - mat.elements[0][3] * b0;
        inv.elements[3][1] = +mat.elements[0][0] * b3 - mat.elements[0][1] * b1 + mat.elements[0][2] * b0;
        inv.elements[0][2] = +mat.elements[3][1] * a5 - mat.elements[3][2] * a4 + mat.elements[3][3] * a3;
        inv.elements[1][2] = -mat.elements[3][0] * a5 + mat.elements[3][2] * a2 - mat.elements[3][3] * a1;
        inv.elements[2][2] = +mat.elements[3][0] * a4 - mat.elements[3][1] * a2 + mat.elements[3][3] * a0;
        inv.elements[3][2] = -mat.elements[3][0] * a3 + mat.elements[3][1] * a1 - mat.elements[3][2] * a0;
        inv.elements[0][3] = -mat.elements[2][1] * a5 + mat.elements[2][2] * a4 - mat.elements[2][3] * a3;
        inv.elements[1][3] = +mat.elements[2][0] * a5 - mat.elements[2][2] * a2 + mat.elements[2][3] * a1;
        inv.elements[2][3] = -mat.elements[2][0] * a4 + mat.elements[2][1] * a2 - mat.elements[2][3] * a0;
        inv.elements[3][3] = +mat.elements[2][0] * a3 - mat.elements[2][1] * a1 + mat.elements[2][2] * a0;


        inv = inv * inv_det;

        return inv;
    }




    export auto transpo(lm44& mat) -> lm44 {

        float temp = mat.elements[0][1];
        mat.elements[0][1] = mat.elements[1][0];
        mat.elements[1][0] = temp;

        temp = mat.elements[0][2];
        mat.elements[0][2] = mat.elements[2][0];
        mat.elements[2][0] = temp;

        temp = mat.elements[0][3];
        mat.elements[0][3] = mat.elements[3][0];
        mat.elements[3][0] = temp;

        temp = mat.elements[1][2];
        mat.elements[1][2] = mat.elements[2][1];
        mat.elements[2][1] = temp;

        temp = mat.elements[1][3];
        mat.elements[1][3] = mat.elements[3][1];
        mat.elements[3][1] = temp;

        temp = mat.elements[2][3];
        mat.elements[2][3] = mat.elements[3][2];
        mat.elements[3][2] = temp;

        return mat;
    }



    export auto operator*(lv4 ve, float s_float) -> lv4 {
        ve.x = ve.x * s_float;
        ve.y = ve.y * s_float;
        ve.z = ve.z * s_float;
        ve.w = ve.w * s_float;

        return ve;
    }
    export auto operator-(lv4 ve, float s_float) -> lv4 {
        ve.x = ve.x - s_float;
        ve.y = ve.y - s_float;
        ve.z = ve.z - s_float;
        ve.w = ve.w - s_float;

        return ve;
    }

    export lv3 unProject(lv3 one3, lm44 view, lm44 proj, lv4& ve4) {
        lm44 inv = inverse(proj * view);

        lv4 tmp = *new lv4(one3, 1.0f);

        tmp.x = (tmp.x - ve4.x) / ve4.z;
        tmp.y = (tmp.y - ve4.y) / ve4.w;

        tmp = tmp * 2 - 1;

        lv4 ovkml = inv * tmp;

        return lv3(ovkml.x / ovkml.w, ovkml.y / ovkml.w, ovkml.z / ovkml.w);
    }

    export lv4 vector_four_matr_four(lv4& lQ, lm44& mat) {
        lv4 backVector;// = LosVector4::LosVector4();


        backVector.x = (mat.elements[0][0] * lQ.x) + (mat.elements[1][0] * lQ.y) + (mat.elements[2][0] * lQ.z) + (mat.elements[3][0] * lQ.w);


        backVector.y = mat.elements[0][1] * lQ.x + mat.elements[1][1] * lQ.y + mat.elements[2][1] * lQ.z + mat.elements[3][1] * lQ.w;

        backVector.z = mat.elements[0][2] * lQ.x + mat.elements[1][2] * lQ.y + mat.elements[2][2] * lQ.z + mat.elements[3][2] * lQ.w;


        backVector.w = mat.elements[0][3] * lQ.x + mat.elements[1][3] * lQ.y + mat.elements[2][3] * lQ.z + mat.elements[3][3] * lQ.w;



        return backVector;
    }
    export auto operator*(lm33& lMat, lv3& lVec) -> lv3 {
        lv3 backVect;
        backVect.x = lMat.elements[0][0] * lVec.x + lMat.elements[1][0] * lVec.y + lMat.elements[2][0] * lVec.z;
        backVect.y = lMat.elements[0][1] * lVec.x + lMat.elements[1][1] * lVec.y + lMat.elements[2][1] * lVec.z;
        backVect.z = lMat.elements[0][2] * lVec.x + lMat.elements[1][2] * lVec.y + lMat.elements[2][2] * lVec.z;

        return backVect;
    }
    export auto operator*(lv3& lVec, lm33& lMat) -> lv3 {
        lv3 backVect;
        backVect.x = lMat.elements[0][0] * lVec.x + lMat.elements[0][1] * lVec.y + lMat.elements[0][2] * lVec.z;
        backVect.y = lMat.elements[1][0] * lVec.x + lMat.elements[1][1] * lVec.y + lMat.elements[1][2] * lVec.z;
        backVect.z = lMat.elements[2][0] * lVec.x + lMat.elements[2][1] * lVec.y + lMat.elements[2][2] * lVec.z;

        return backVect;
    }


    //  // -1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f
    export lm44 orthonormalMatrixRight(float left, float right, float bottom, float top, float zNear, float zFar) {
        lm44 orthoMatrix;
        orthoMatrix = identity();

        /*[0][0]  [1][0]  [2][0]  [3][0]
          [0][1]  [1][1]  [2][1]  [3][1]
          [0][2]  [1][2]  [2][2]  [3][2]
          [0][3]  [1][3]  [2][3]  [3][3]   */


          //    Result[0][0] = static_cast<T>(2) / (right - left);
          //    Result[1][1] = static_cast<T>(2) / (top - bottom);
          //    Result[2][2] = - static_cast<T>(2) / (zFar - zNear);
          //    Result[3][0] = - (right + left) / (right - left);
          //    Result[3][1] = - (top + bottom) / (top - bottom);
          //    Result[3][2] = - (zFar + zNear) / (zFar - zNear);
        orthoMatrix.elements[0][0] = 2 / (right - left);
        orthoMatrix.elements[1][1] = 2 / (top - bottom);
        orthoMatrix.elements[2][2] = -2 / (zFar - zNear);
        orthoMatrix.elements[3][0] = -(right + left) / (right - bottom);
        orthoMatrix.elements[3][1] = -(top + bottom) / (top - bottom);
        orthoMatrix.elements[3][2] = -(zFar + zNear) / (zFar - zNear);

        return orthoMatrix;

    }




}