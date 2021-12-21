using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.Linq;
using System.Threading.Tasks;
using Reports.DAL.Entities;
using Reports.Server.Database;

namespace Reports.Server.Services
{
    public class TaskModelService : ITaskModelService
    {
        private readonly ReportsDatabaseContext _context;
        
        public TaskModelService(ReportsDatabaseContext context) {
            _context = context;
        }
        public async Task<TaskModel> Create(RequestTaskModel requestModel)
        {
            var task = new TaskModel(requestModel.Title, requestModel.Context,
                requestModel.AssignedEmployeeId);
            await _context.Tasks.AddAsync(task);
            await _context.SaveChangesAsync();
            return task;
        }

        public TaskModel FindById(Guid id)
        {
            return _context.Tasks.First(x => Equals(x.Id, id));
        }

        public TaskModel FindByLastUpdate(Guid id)
        {
            return _context.Tasks.ToImmutableSortedSet().Last();
        }
        public List<TaskModel> FindByEmployeeId(Guid id)
        {
            return _context.Tasks.ToList().FindAll(x => Equals(x.AssignedEmployeeId, id));
        }
        public void Delete(Guid id)
        {
            _context.Tasks.Remove(FindById(id));
            _context.SaveChanges();
        }
        public List<TaskModel> GetAll()
        {
            return _context.Tasks.ToList();
        }
        public void Update(RequestTaskUpdateModel requestTaskModel)
        {
            TaskModel task = FindById(requestTaskModel.Id);
            task.Context = requestTaskModel.Context;
            task.Title = requestTaskModel.Title;
            task.AssignedEmployeeId = requestTaskModel.AssignedEmployeeId;
            task.LastUpdateOn = DateTime.Now;
            task.TaskStatus = requestTaskModel.TaskStatus;
            _context.Update(task);
            _context.SaveChanges();
        }
    }
}
