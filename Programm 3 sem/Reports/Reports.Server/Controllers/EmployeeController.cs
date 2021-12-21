using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Reports.DAL.Entities;
using Reports.Server.Services;

namespace Reports.Server.Controllers
{
    [ApiController]
    public class EmployeeController : ControllerBase
    {
        private readonly IEmployeeService _service;

        public EmployeeController(IEmployeeService service)
        {
            _service = service;
        }
        
        [Route("/employees")]
        [HttpGet]
        public List<Employee> GetAll()
        {
            return _service.GetAll();
        }

        [Route("/employees/create")]
        [HttpPost]
        public async Task<Employee> Create([FromQuery] string name, [FromQuery] Guid bossId)
        {
            return await _service.Create(name, bossId);
        }
        
        [Route("/employees/delete")]
        [HttpPost]
        public void Delete([FromQuery] Guid id)
        {
            _service.Delete(id);
        }
        
        
        [Route("/employees/find")]
        [HttpGet]
        public IActionResult Find([FromQuery] Guid id)
        {
            Employee employee = _service.FindById(id);
            if (employee != null)
            {
                return Ok(employee);
            }
            return NotFound();
        }
    }
}