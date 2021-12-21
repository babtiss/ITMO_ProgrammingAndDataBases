using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Reports.DAL.Entities;

namespace Reports.Server.Services
{
    public interface ITaskModelService
    {
        Task<TaskModel> Create(RequestTaskModel requestModel);
        List<TaskModel> GetAll();
        TaskModel FindById(Guid id);
        TaskModel FindByLastUpdate(Guid id);
        List<TaskModel> FindByEmployeeId(Guid id);
        
        void Delete(Guid id);
        void Update(RequestTaskUpdateModel requestTaskModel);
    }
}