using CapaEntidad;

namespace CapaDatos
{
    public class TipoMedicamentoDAI
    {
        public List<TipoMedicamentoCLS> ListarTipoMedicamento()
        {
            var lista = new List<TipoMedicamentoCLS>();

            lista.Add(new TipoMedicamentoCLS
            {
                idMedicamento = 1,
                nombre = "Paracetamol",
                descripcion = "Medicamento para el dolor"
            });
            lista.Add(new TipoMedicamentoCLS
            {
                idMedicamento = 2,
                nombre = "Inyecciones",
                descripcion = "Desc 2"
            });

            lista.Add(new TipoMedicamentoCLS
            {
                idMedicamento = 3,
                nombre = "Pastillas",
                descripcion = "Desc 3"
            });

            return lista;
        }
    }
}
