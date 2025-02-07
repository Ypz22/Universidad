using CapaDatos;
using CapaEntidad;
namespace CapaNegocio;

public class TipoMedicamentoBL
{
    public List<TipoMedicamentoCLS> ListarTipoMedicamento()
    {
        var lista = new List<TipoMedicamentoCLS>();

        TipoMedicamentoDAI obj = new TipoMedicamentoDAI();

        return obj.ListarTipoMedicamento();
    }
}
