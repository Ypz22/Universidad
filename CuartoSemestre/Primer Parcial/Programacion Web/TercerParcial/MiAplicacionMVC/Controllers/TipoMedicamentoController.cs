using Microsoft.AspNetCore.Mvc;
using CapaNegocio;
using CapaEntidad;

namespace MyApp.Namespace
{
    public class TipoMedicamentoController : Controller
    {
        // GET: TipoMedicamentoController
        public IActionResult Index()
        {
            return View();
        }

        public IActionResult Inicio()
        {
            return View();
        }

        public IActionResult SinMenu()
        {
            return View();
        }

        public string Saludo()
        {
            return "Hola desde el controlador de tipo medicamento";
        }

        public double Calcular()
        {
            return 3.1416;
        }

        public string SaludoConNombre(string nombre)
        {
            return "Hola " + nombre + " desde el controlador de tipo medicamento";
        }

        public string SaludoCompleto(string nombre, string apellido)
        {
            return "Hola " + nombre + apellido + "  desde el controlador de tipo medicamento";
        }

        public List<TipoMedicamentoCLS> listarTipoMedicamento()
        {
            TipoMedicamentoBL obj = new TipoMedicamentoBL();

            return obj.ListarTipoMedicamento();
        }

    }
}
