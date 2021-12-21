using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Reports.DAL.Entities;
using Reports.Server.Services;

namespace Reports.Server.Controllers
{
    [ApiController]
    public class TasksController : ControllerBase
    {
        private readonly ITaskModelService _service;

        public TasksController(ITaskModelService service)
        {
            _service = service;
        }
        
        [Route("/tasks/create")]
        [HttpPost]
        public async Task<TaskModel> Create([FromBody] RequestTaskModel requestModel)
        {
            return await _service.Create(requestModel);
        }
        
        [Route("/tasks")]
        [HttpGet]
        public List<TaskModel> GetAll()
        {
            return _service.GetAll();
        }
        
        [Route("/tasks/delete")]
        [HttpPost]
        public void Delete([FromQuery] Guid id)
        {
            _service.Delete(id);
        }
        
        [Route("/tasks/find-by-id")]
        [HttpGet]
        public TaskModel FindById([FromQuery] Guid id)
        {
            return  _service.FindById(id);
        }
        
        [Route("/tasks/find-by-employee")]
        [HttpGet]
        public List<TaskModel> FindByEmployee([FromQuery] Guid employeeId)
        {
            return _service.FindByEmployeeId(employeeId);
        }

        [Route("/tasks/update")]
        [HttpPost]
        public void Update([FromBody] RequestTaskUpdateModel requestTaskModel)
        {
            _service.Update(requestTaskModel);
        }
    }
}