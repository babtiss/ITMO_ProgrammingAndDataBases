using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Reports.DAL.Entities;
using Reports.Server.Services;

namespace Reports.Server.Controllers
{
    [ApiController]
    public class ReportController : ControllerBase
    {
        private readonly IReportService _service;

        public ReportController(IReportService service)
        {
            _service = service;
        }
        
        [Route("/reports/create")]
        [HttpPost]
        public async Task<Report> Create([FromBody] Report.RequestReport requestModel)
        {
            return await _service.Create(requestModel);
        }
        
        [Route("/reports")]
        [HttpGet]
        public List<Report> GetAll()
        {
            return _service.GetAll();
        }
        
        [Route("/reports/delete")]
        [HttpPost]
        public void Delete([FromQuery] Guid id)
        {
            _service.Delete(id);
        }
        
        [Route("/reports/find")]
        [HttpGet]
        public Report Find([FromQuery] Guid id)
        {
            return _service.FindById(id);
        }
        [Route("/reports/update")]
        [HttpPost]
        public void Update([FromBody] Report.RequestReportUpdate requestModel)
        {
            _service.Update(requestModel);
        }
        
    }
}