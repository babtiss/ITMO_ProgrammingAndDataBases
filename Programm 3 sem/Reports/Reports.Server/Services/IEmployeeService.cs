using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Reports.DAL.Entities;

namespace Reports.Server.Services
{
    public interface IEmployeeService
    {
        Task<Employee> Create(string name, Guid bossId);
        List<Employee> GetAll();
        Employee FindById(Guid id);
        void Delete(Guid id);
        

    }
}