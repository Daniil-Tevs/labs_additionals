template<typename T, int N, int M>
struct MasWrapper
{
    T mas[N][M];
};

template <typename T, int N, int M>
class matrix{
public:
    matrix()
    {
        m_n = N;
        m_m = M;
        for(int i=0;i<N;i++)
            for(int j = 0;j<M;j++)
                m_mat[i][j]=0;
    }
    matrix(const T mas[N][M])
    {
        m_n = N;
        m_m = M;
        for (int i = 0; i < m_n; i++)
            for (int j = 0; j < m_m; j++)
                m_mat[i][j] = mas[i][j];
    }
    matrix(const matrix<T,N,M>& mas)
    {
        m_n = mas.m_n;
        m_m = mas.m_m;
        for(int i=0;i<m_n;i++)
            for(int j=0;j<m_m;j++)
                m_mat[i][j]=mas.m_mat[i][j];
    }
    matrix(const MasWrapper<T, N, M>& mas)
    {

        m_n = N;
        m_m = M;
        for (int i = 0; i < m_n; i++)
            for (int j = 0; j < m_m; j++)
                m_mat[i][j] = mas.mas[i][j];
    }

    matrix<T,N,M>& operator=(const matrix<T,N,M>& mas)
    {
        m_n = mas.m_n;
        m_m = mas.m_m;
        for(int i=0;i<m_n;i++)
            for(int j=0;j<m_m;j++)
                m_mat[i][j]=mas.m_mat[i][j];
        return *this;
    }
    matrix<T,N,M>& operator+(const matrix<T,N,M>& mas)
    {
        matrix<T,N,M> tmp;
        for(int i=0;i<m_n;i++)
            for(int j=0;j<m_m;j++)
                tmp.m_mat[i][j]=m_mat[i][j]+mas.m_mat[i][j];
        return tmp;
    }
    matrix<T,N,M>& operator-(const matrix<T,N,M>& mas)
    {
        matrix<T,N,M> tmp;
        for(int i=0;i<m_n;i++)
            for(int j=0;j<m_m;j++)
                tmp.m_mat[i][j]=m_mat[i][j]-mas.m_mat[i][j];
        return tmp;
    }
    template <typename T, int N, int M>
    matrix<T, N, M> operator*(const matrix<T, N, M>& mat)
    {
        matrix<T, N, M> tmp;

        for (int i = 0; i < m_n; i++)
            for (int j = 0; j < mat.getM(); j++)
            {
                T sum = 0;
                for (int k = 0; k < m_m; k++)
                    sum += m_mat[i][k] * mat.get(k, j);
                tmp.set(i, j, sum);
            }

        return tmp;

    }
    ~matrix(){};
    template<typename T,int N,int M>
    friend std::istream& operator>>(std::istream& in,matrix<T,N,M>& mat);
    template<typename T,int N,int M>
    friend std::ostream& operator<<(std::ostream& out,matrix<T,N,M>& mat);
    int getN() const {return N;}
    int getM() const {return M;}
    T get(int i,int j) const {return m_mat[i][j];}
    void set(int i,int j,T data) {m_mat[i][j]=data;}
    T determinate()
    {
        if(m_n==m_m && (m_n==2 || m_n==3))
        {
            if(m_n==2)
                return m_mat[0][0]*m_mat[1][1]-m_mat[0][1]*m_mat[1][0];
            T D=0;
            D+=m_mat[0][0]*(m_mat[1][1]*m_mat[2][2]-m_mat[1][2]*m_mat[2][1]);
            D+=-m_mat[0][1]*(m_mat[1][0]*m_mat[2][2]-m_mat[1][2]*m_mat[2][0]);
            D+=m_mat[0][2]*(m_mat[1][0]*m_mat[2][1]-m_mat[1][1]*m_mat[2][0]);
            return D;
        }
        else if(m_n==m_m && m_n==1)
            return m_mat[0][0];
        else { std::cout << "This operate isn't working now" << std::endl; return -1;}
    }
    matrix<double,N,M> inverse()
    {
        if(m_n==m_m && (m_n==3))
        {
            T det = determinate();
            T mas[2][2];
            matrix<double, N, M> tmp;
            for (int i = 0; i < m_n; i++)
                for (int j = 0; j < m_m; j++) {
                    mas[0][0] = m_mat[(j % 3 + 1) % 3][(i % 3 + 1) % 3];
                    mas[0][1] = m_mat[(j % 3 + 1) % 3][(i % 3 + 2) % 3];
                    mas[1][0] = m_mat[(j % 3 + 2) % 3][(i % 3 + 1) % 3];
                    mas[1][1] = m_mat[(j % 3 + 2) % 3][(i % 3 + 2) % 3];
                    if(j==1){ std::swap(mas[0][0],mas[1][0]);
                        std::swap(mas[0][1],mas[1][1]);}
                    if(i==1){ std::swap(mas[0][0],mas[0][1]);
                        std::swap(mas[1][0],mas[1][1]);}
                    tmp.set(i,j,double (pow(-1, i + j) * a_d(mas) /det));
                }
            return tmp;
        }
        else if(m_n==m_m && (m_n==2))
        {
            T det = determinate();
            matrix<double, N, M> tmp;
            for(int i=0;i<m_n;i++)
                for(int j=0;j<m_m;j++)
                {
                    if(i!=j)
                    {tmp.set(i, j, pow(-1, i + j) * m_mat[i][j]/det);}
                    else{tmp.set(i, j, pow(-1, i + j) * m_mat[m_n-i-1][m_m-j-1]/det);}
                }
            return tmp;
        }
        else { std::cout << "This operate isn't working now" << std::endl;}
    }
    matrix<T,N,M> transposition()
    {
        matrix<T,N,M> tmp;
        for(int i=0;i<m_n;i++)
            for(int j=0;j<m_m;j++)
                tmp.set(i,j,m_mat[j][i]);
        return tmp;
    }
private:
    int m_n,m_m;
    T m_mat[N][M];
    T a_d(T mas[2][2]){return mas[0][0]*mas[1][1]-mas[0][1]*mas[1][0];}
};
template<typename T,int N,int M>
std::istream& operator>>(std::istream& in,matrix<T,N,M>& mat)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            in>>mat.m_mat[i][j];
    return in;
}
template<typename T,int N,int M>
std::ostream& operator<<(std::ostream& out,matrix<T,N,M>& mat)
{
    for(int i=0;i<N;i++) {
        for (int j = 0; j < M; j++)
            out << mat.m_mat[i][j] << " ";
        out<<std::endl;
    }
    return out;
}

using mat22i = matrix<int,2,2>;
using mat22d = matrix<double,2,2>;
using vec2i = matrix<int,2,1>;
using vec2d = matrix<double,2,1>;